#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#define PCB_NUM 6
typedef struct PCB{//声明新的结构体类型
    int id;                            /* 进程id */
    char name[10];                    /* 进程标识符 */
    int allTime;                       /* 进程共需要占用 CPU 时间 */
    int needTime;                      /* 进程到完成还需要的时间 */
    int cpuTime;                      /* 进程已经占用CPU的时间 */
    int startBlock;                      /* 开始阻塞的时刻，-1表示不会发生阻塞*/
    int blockTime;                      /* 阻塞消耗的总时间 */
    int block_start_time;//我自己添加的一个标注开始阻塞的绝对时间，用于判断阻塞结束
    char state;                        /* 进程的状态：就绪、阻塞、运行、完成*/
    PCB *next;                  /*链指针*/
}PCB;
PCB  PCB_init[PCB_NUM];




typedef struct PCB_QuNode {//声明新的结构体队列类型
    PCB*front;
    PCB*rear;
}PCB_QuNode;
int time=-1;//时间计数器
PCB_QuNode  *ready;//就绪队列
PCB_QuNode  *block;//阻塞队列
PCB_QuNode  *finish;//完成队列


void enPCB_QuNode(PCB *p,PCB_QuNode *q);

//初始化三个队列，将文件读入PCB_init[]和ready
void start(){
    ready = (PCB_QuNode *)malloc(sizeof(PCB_QuNode));
    ready->front=ready->rear=NULL;

    finish = (PCB_QuNode *)malloc(sizeof(PCB_QuNode));
    finish->front=finish->rear=NULL;

    block = (PCB_QuNode *)malloc(sizeof(PCB_QuNode));
    block->front=block->rear=NULL;
//从文件读取信息到PCB_init中,再放到ready中
    FILE *fp =fopen("C:\\c++\\.vs\\ForkCommunciate\\textC:\\c++\\.vs\\ForkCommunciate\\text.txt", "r");
    for(int i=0;i<PCB_NUM;i++)
    {	fscanf(fp, "%d", &PCB_init[i].id);
        fscanf(fp, "%s", PCB_init[i].name);
        fscanf(fp, "%d", &PCB_init[i].allTime);
        fscanf(fp, "%d", &PCB_init[i].needTime);
        fscanf(fp, "%d", &PCB_init[i].cpuTime);
        fscanf(fp, "%d", &PCB_init[i].startBlock);
        fscanf(fp, "%d", &PCB_init[i].blockTime);
        PCB_init[i].state = 'r';
        enPCB_QuNode(&PCB_init[i],ready);
    }
}

//输出所有的PCB的信息
void outputAll() {
    printf("========================================================================\n");
    printf("id\tname\tallTime\tneedTime\tcpuTime\tstartBlock\tblockTime state\n");
    printf("========================================================================\n");
    for(int i=0;i<PCB_NUM;i++){
        printf("%d\t%s\t%d\t%d\t\t%d\t%d\t\t%d\t%c\n",PCB_init[i].id,PCB_init[i].name,PCB_init[i].allTime,PCB_init[i].needTime,PCB_init[i].cpuTime,PCB_init[i].startBlock,PCB_init[i].blockTime,PCB_init[i].state);
    }
}

//输出所有队列的情况
void outputQueu(){
    printf("就绪队列：");
    PCB *pre = ready->front;
    while(pre != NULL){
        printf("%s\t",pre->name);
        pre = pre->next;
    }
    printf("\n");

    printf("阻塞队列：");
    pre = block->front;
    while(pre != NULL){
        printf("%s\t",pre->name);
        pre = pre->next;
        //printf("这里？");
    }
    printf("\n");

    printf("完成队列：");
    pre = finish->front;
    while(pre != NULL){
        printf("%s\t",pre->name);
        pre = pre->next;
    }
    printf("\n");
}

//传入一个队列和PCB，进行入队操作
void enPCB_QuNode(PCB *p,PCB_QuNode *q){
    p->next = NULL;
    if(q->rear == NULL){
        q->front=q->rear=p;
    }else{
        q->rear->next=p;
        q->rear = p;
    }
}
//出队（不包括阻塞队列），返回出队的PCB
PCB* dePCB_QuNode(PCB_QuNode*q){
    PCB*p;
    p = q->front;
    if(q->front == q->rear){
        q->front = q->rear = NULL;
    }else{
        q->front = q->front->next;
    }
    return p;
}
//自写
PCB* dePCB_QuNode_block(int n ,PCB_QuNode*q){//出队（不包括阻塞队列），返回出队的PCB
    PCB*p;
    PCB*temp;
    p = q->front;

    if(q->front == q->rear){
        q->front = q->rear = NULL;
        return p;
    }else if(n==1){
        q->front = q->front->next;
        return p;
    }
    while(1){
        if(n == 1)break;
        p = p->next;
        n--;
    }
    temp = p;
    p = temp->next;
    if(p->next == NULL)q->rear = temp;
    else temp->next = p->next;

    return p;
}
//检查阻塞进程，比较startblock+blocktime和当前时间,阻塞结束的移出到就绪队列尾部
void Judge_block(){
    PCB*p=block->front;
    //计数，在队列的位置
    int local = 0;
    if(p == NULL)return;

    PCB*temp;
    while(p != NULL){
        local = local +1;
        if(p->block_start_time+p->blockTime ==time){//阻塞结束
            temp = dePCB_QuNode_block(local,block);
            temp->state = 'w';//变为就绪
            enPCB_QuNode(temp,ready);//入队，到就绪队列
        }
        p=p->next;
    }
}
//判断+1后运行的进程的状态
void Judge_run(){
    ready->front->needTime--;
    ready->front->cpuTime++;
    PCB*temp;
    temp = ready->front;
    if(ready->front->needTime == 0){//完成了进程
        temp = dePCB_QuNode(ready);//出队
        temp->state = 'f';
        enPCB_QuNode(temp,finish);//入队到结束
        return;
    }else if(ready->front->cpuTime == ready->front->startBlock){//到达阻塞状态
        temp = dePCB_QuNode(ready);//出队
        temp->block_start_time = time;//添加的
        temp->state = 'b';
        enPCB_QuNode(temp,block);
    }else if(time%2==0 && time!=0){//时间片结束，中断运行，进入就绪
        temp = dePCB_QuNode(ready);//出队
        temp->state = 'w';
        enPCB_QuNode(temp,ready);//入队ready
    }
}

int main(){
    start();
//return 0;
    printf("-----------------------------------------------------------------\n");
    printf("\t\t\t\t程序开始\n");
    printf("-----------------------------------------------------------------\n");
//设state = r为运行，w为就绪，b为阻塞，f为结束，时间片设为2
//先令就绪队列的首进程其处于运行状态
    time = time+1;
    if(ready->rear != NULL)ready->front->state = 'r';
    outputAll();
    outputQueu();
//初始状态结束
    while(ready->rear != NULL || block->rear != NULL){
        time=time+1;
        printf("--------------------------------------------------------------------------------\n");
        printf("当前时间：%d\n",time);
        if(ready->rear != NULL)ready->front->state = 'r';
        //输出当前状态
        Judge_run();//运行检查，放到该放的地方去
        Judge_block();//检查阻塞，并把符合条件的放到就绪
        outputAll();
        outputQueu();
    }
}
