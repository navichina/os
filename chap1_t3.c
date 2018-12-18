#include<stdio.h>
#include<unistd.h>
int main(){
int i,j;
for(i=0;i<3;i++)
 { j=fork();
   if(j==0)  printf("我是第%d个进程\n",i);
   fflush(stdout);
  }
return 0;
}
