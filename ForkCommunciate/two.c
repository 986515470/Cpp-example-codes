
#include<stdio.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<signal.h>
#include<unistd.h>
#include <ctype.h>
#define BUF_SIZE 100
#define SHM_SIZE 1024

char *strUpr(char *str){
    char *orign=str;
    for (; *str!='\0'; str++)
        *str = toupper(*str);
    return orign;
}//大写

char *strLower(char *str){
    char *orign=str;
    for (; *str!='\0'; str++)
        *str = tolower(*str);
    return orign;
}//小写

void handler1(int sig){
    if ( SIGUSR1 == sig ){
        printf("父进程数据写入完毕！\r\n");
    }
}

void handler2(int sig){
    if ( SIGUSR2 == sig ){
        printf("子进程回复完毕,结束进程！\r\n");
    }
}

int main(void)
{
    key_t key = 0;
    int ret = 0;
    int shmid = 0;
    pid_t pid;
    char * pShm = NULL;
    char buf[BUF_SIZE] = {'\0'};

    key = ftok( "/tmp", 23 );
    if ( 0 > key ){
        perror("ftok error");
        return -1;
    }

    shmid = shmget(key, SHM_SIZE, 0644 | IPC_CREAT);
    if ( 0 > shmid ){
        perror("shmget error");
        return -1;
    }

    pShm = shmat(shmid, NULL, 0);
    if ( (void *)-1  == pShm ){
        perror("shmat error");
        shmctl(shmid, IPC_RMID, NULL);
        return -1;
    }

    pid = fork();//创建
    if ( 0 > pid )
    {
        perror("fork error");
        shmctl(shmid, IPC_RMID, NULL);
        return -1;
    }
    else if ( 0 < pid )
    {
        signal(SIGUSR2, handler2);
        while(1)
        {
            printf("Father send to Son:");
            fgets(pShm, SHM_SIZE, stdin);    //写入
            kill(pid,SIGUSR1);//向子进程发送
            pause(); //读取共享内存中数据
            printf("Father last get（before treatment）:%s\r",pShm);//最后得到的信息
            pShm=strUpr(pShm);
            printf("Father last show（After treatment）:%s\r",pShm);

            kill(pid, SIGUSR1);
            break;
        }
        printf("Father end!\n");

        shmdt(pShm);
        shmctl(shmid, IPC_RMID, NULL);
    }
    else
    {
        pid_t ppid;
        ppid = getppid();
        signal(SIGUSR1, handler1);
        while(1)
        {
            pause();
            printf("Son get（before treatment）:%s\r",pShm);//得到传来的信息
            pShm=strLower(pShm);
            printf("Son show（After treatment）：%s\r",pShm);//展示处理后的信息
            printf("Son reply to Father:");
            fgets(pShm, SHM_SIZE, stdin);    //回复
            printf("Son send message：%s\r",pShm);//展示处理后的信息
            kill(ppid,SIGUSR2);
            break;
        }
        printf("Son end!\n");
    }
    return 0;
}


 