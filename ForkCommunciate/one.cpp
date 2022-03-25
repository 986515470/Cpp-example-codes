#include <iostream>
#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/shm.h>
#include <string.h>

struct shareMemory{

    int written_by_you;
    char some_text[1024];
};
using namespace std;
int main()
{
    key_t  key_n ;
    int    shm_id;
    pid_t  pid;
    int running = 1;   //决定是否继续运行的变量
    void *Shared_Memory = NULL;  //共享内存的首地址
    struct shareMemory *shared_stuff;
    char buf[2048];

    if((key_n = ftok("/",'s')<0))  //生成共享内存的key值
    {
        perror("Fail to ftok");
        exit(EXIT_SUCCESS);
    }
    printf("key num:%d\n",key_n);

    if((shm_id = shmget(key_n,1024,0666|IPC_CREAT))==-1)  //创建共享内存
    {
        perror("Fail to shmget");
        exit(EXIT_SUCCESS);
    }
    printf("share memory id:%d\n",shm_id);
    printf("share memory  size:%d\n",1024);

    if((pid = fork())==-1)
    {
        perror("Fail to fork");
        exit(EXIT_SUCCESS);
    }

    if(pid!=0)                                         //父进程，用来读
    {
        printf("Father process: %d\n",pid);
        Shared_Memory = shmat(shm_id,0,0);                     //将共享内存连接到当前进程的地址空间
        if(Shared_Memory==(void *)-1)
        {
            perror("Fail to shmat");
            exit(EXIT_SUCCESS);
        }
//        printf(" Son Memory attached at %x\n",(int)Shared_Memory);
        cout<<"Father Memory attached at:  "<<Shared_Memory<<"\n";

        shared_stuff = (struct shareMemory *)Shared_Memory;        //设置共享内存
        shared_stuff->written_by_you = 0;

        while(running)  //读取共享内存中的数据
        {
            if(shared_stuff->written_by_you!=0)
            {
                printf("回到父进程:You just Wrote:%s",shared_stuff->some_text);
                cout<<"exiting...\n";
                sleep(rand()%4);
                running=0;//退出
            }
        }
        if(shmdt(Shared_Memory)==-1){
            perror("Fail to Shmdt");
            exit(EXIT_SUCCESS);
        }
        if(shmctl(shm_id,IPC_RMID,0)==-1){
            perror("Fail to shmctl");
            exit(EXIT_SUCCESS);
        }
        exit(EXIT_SUCCESS);
    }else                                       //子进程，用来写
    {

        printf("Son process:%d\n",pid);
        Shared_Memory = shmat(shm_id,0,0);
        if(Shared_Memory==(void *)-1)
        {
            perror("Fail to shmat");
            exit(EXIT_SUCCESS);
        }
//        printf("father Memory attached at %x\n",(int)Shared_Memory);
        cout<<"Son Memory attached at:  "<<Shared_Memory<<"\n";

        shared_stuff = (struct shareMemory *)Shared_Memory;
        shared_stuff->written_by_you = 0;

        while(running)  //向共享内存中写数据
        {
            while(shared_stuff->written_by_you==1)
            {
                sleep(1);
            }
            //向共享内存中写入数据
            printf("调用子进程:input your words:");
            fgets(buf,1024,stdin);
            strncpy(shared_stuff->some_text,buf,1024);
            shared_stuff->written_by_you = 1;
            if(strncmp(shared_stuff->some_text,"end",3)==0){
                running = 0;
            }
        }

        if(shmdt(Shared_Memory)==-1){
            perror("Fail to Shmdt");
            exit(EXIT_SUCCESS);
        }//分离
        exit(EXIT_SUCCESS);
    }

    return 0;
}