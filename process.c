#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

int main()
{
    int i,ret;
    printf("PID : %d\t CID : %d\n",getppid(), getpid());
    for(i=0;i<3;i++)
    {
        ret=fork();
        if(ret==0)
        {
            printf(" PID : %d\t CID : %d\n",getppid(), getpid());
            break;
        }
    return 0;
}