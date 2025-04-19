#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

//writer
void main()
{
    int id;
    int *sm;
    char buff[100];
    id=shmget((key_t)1222,1024,0666 | IPC_CREAT);
    printf("key to the shared memory is:%d",id);
    sm=shmat(id,NULL,0);
    printf("process attached at %p",sm);
    printf("\nEnter data to be entered:\n");
    read(0,buff,100);
    strcpy(sm,buff);
    printf("Written data is : \n%s",(char*)sm);

}

//reader
void main()
{
    int id;
    int *sm;
    char buff[100];
    id = shmget((key_t)1222,1024,0666);
    printf("key to the shared memory is:%d\n",id);
    sm=shmat(id,NULL,0);
    printf("process is attached at %p\n",sm);
    printf("data in memory is \n%s\n ",(char*)sm);
    strcpy(buff,sm);
    int a=buff[0]-'0';
    int b=buff[2]-'0';
    printf("sum=%d"a+b);
}
