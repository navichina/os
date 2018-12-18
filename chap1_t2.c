#include<stdio.h>
#include<unistd.h>
int main(){
   pid_t pid;
   for(int i = 0; i < 3; i++)
   {
        pid = fork();
        printf("我是第%d个进程 X %d\n",pid,i);
        printf("我是第%d个进程 Y %d\n",pid,i);
        fflush(stdout);
  }
}
