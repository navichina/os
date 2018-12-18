#include <stdio.h>
#include <unistd.h>
int main()
{
    int i,j;
    for(i=0;i<3;i++)
    {
       j=fork();
       if(j==0)
           printf("这是第%d个进程 X %d \n",j,i);
       else  printf("这是第%d个进程 Y %d\n",j,i);
       fflush(stdout);
    }
}
