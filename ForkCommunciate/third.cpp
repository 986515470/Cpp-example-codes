#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#define PCB_NUM 6
typedef struct PCB{//�����µĽṹ������
    int id;                            /* ����id */
    char name[10];                    /* ���̱�ʶ�� */
    int allTime;                       /* ���̹���Ҫռ�� CPU ʱ�� */
    int needTime;                      /* ���̵���ɻ���Ҫ��ʱ�� */
    int cpuTime;                      /* �����Ѿ�ռ��CPU��ʱ�� */
    int startBlock;                      /* ��ʼ������ʱ�̣�-1��ʾ���ᷢ������*/
    int blockTime;                      /* �������ĵ���ʱ�� */
    int block_start_time;//���Լ���ӵ�һ����ע��ʼ�����ľ���ʱ�䣬�����ж���������
    char state;                        /* ���̵�״̬�����������������С����*/
    PCB *next;                  /*��ָ��*/
}PCB;
PCB  PCB_init[PCB_NUM];




typedef struct PCB_QuNode {//�����µĽṹ���������
    PCB*front;
    PCB*rear;
}PCB_QuNode;
int time=-1;//ʱ�������
PCB_QuNode  *ready;//��������
PCB_QuNode  *block;//��������
PCB_QuNode  *finish;//��ɶ���


void enPCB_QuNode(PCB *p,PCB_QuNode *q);

//��ʼ���������У����ļ�����PCB_init[]��ready
void start(){
    ready = (PCB_QuNode *)malloc(sizeof(PCB_QuNode));
    ready->front=ready->rear=NULL;

    finish = (PCB_QuNode *)malloc(sizeof(PCB_QuNode));
    finish->front=finish->rear=NULL;

    block = (PCB_QuNode *)malloc(sizeof(PCB_QuNode));
    block->front=block->rear=NULL;
//���ļ���ȡ��Ϣ��PCB_init��,�ٷŵ�ready��
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

//������е�PCB����Ϣ
void outputAll() {
    printf("========================================================================\n");
    printf("id\tname\tallTime\tneedTime\tcpuTime\tstartBlock\tblockTime state\n");
    printf("========================================================================\n");
    for(int i=0;i<PCB_NUM;i++){
        printf("%d\t%s\t%d\t%d\t\t%d\t%d\t\t%d\t%c\n",PCB_init[i].id,PCB_init[i].name,PCB_init[i].allTime,PCB_init[i].needTime,PCB_init[i].cpuTime,PCB_init[i].startBlock,PCB_init[i].blockTime,PCB_init[i].state);
    }
}

//������ж��е����
void outputQueu(){
    printf("�������У�");
    PCB *pre = ready->front;
    while(pre != NULL){
        printf("%s\t",pre->name);
        pre = pre->next;
    }
    printf("\n");

    printf("�������У�");
    pre = block->front;
    while(pre != NULL){
        printf("%s\t",pre->name);
        pre = pre->next;
        //printf("���");
    }
    printf("\n");

    printf("��ɶ��У�");
    pre = finish->front;
    while(pre != NULL){
        printf("%s\t",pre->name);
        pre = pre->next;
    }
    printf("\n");
}

//����һ�����к�PCB��������Ӳ���
void enPCB_QuNode(PCB *p,PCB_QuNode *q){
    p->next = NULL;
    if(q->rear == NULL){
        q->front=q->rear=p;
    }else{
        q->rear->next=p;
        q->rear = p;
    }
}
//���ӣ��������������У������س��ӵ�PCB
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
//��д
PCB* dePCB_QuNode_block(int n ,PCB_QuNode*q){//���ӣ��������������У������س��ӵ�PCB
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
//����������̣��Ƚ�startblock+blocktime�͵�ǰʱ��,�����������Ƴ�����������β��
void Judge_block(){
    PCB*p=block->front;
    //�������ڶ��е�λ��
    int local = 0;
    if(p == NULL)return;

    PCB*temp;
    while(p != NULL){
        local = local +1;
        if(p->block_start_time+p->blockTime ==time){//��������
            temp = dePCB_QuNode_block(local,block);
            temp->state = 'w';//��Ϊ����
            enPCB_QuNode(temp,ready);//��ӣ�����������
        }
        p=p->next;
    }
}
//�ж�+1�����еĽ��̵�״̬
void Judge_run(){
    ready->front->needTime--;
    ready->front->cpuTime++;
    PCB*temp;
    temp = ready->front;
    if(ready->front->needTime == 0){//����˽���
        temp = dePCB_QuNode(ready);//����
        temp->state = 'f';
        enPCB_QuNode(temp,finish);//��ӵ�����
        return;
    }else if(ready->front->cpuTime == ready->front->startBlock){//��������״̬
        temp = dePCB_QuNode(ready);//����
        temp->block_start_time = time;//��ӵ�
        temp->state = 'b';
        enPCB_QuNode(temp,block);
    }else if(time%2==0 && time!=0){//ʱ��Ƭ�������ж����У��������
        temp = dePCB_QuNode(ready);//����
        temp->state = 'w';
        enPCB_QuNode(temp,ready);//���ready
    }
}

int main(){
    start();
//return 0;
    printf("-----------------------------------------------------------------\n");
    printf("\t\t\t\t����ʼ\n");
    printf("-----------------------------------------------------------------\n");
//��state = rΪ���У�wΪ������bΪ������fΪ������ʱ��Ƭ��Ϊ2
//����������е��׽����䴦������״̬
    time = time+1;
    if(ready->rear != NULL)ready->front->state = 'r';
    outputAll();
    outputQueu();
//��ʼ״̬����
    while(ready->rear != NULL || block->rear != NULL){
        time=time+1;
        printf("--------------------------------------------------------------------------------\n");
        printf("��ǰʱ�䣺%d\n",time);
        if(ready->rear != NULL)ready->front->state = 'r';
        //�����ǰ״̬
        Judge_run();//���м�飬�ŵ��÷ŵĵط�ȥ
        Judge_block();//������������ѷ��������ķŵ�����
        outputAll();
        outputQueu();
    }
}
