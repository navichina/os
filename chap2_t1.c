#include <unistd.h>
#define N 2
void *thread(void *vargp);
char **ptr; /* Global variable */ 
int main() 
{  
 	int i;
 	pthread_t tid; 
 	char *msgs[N] = { 
 		"Hello from foo",
 		"Hello from bar"
 	}; 
 	ptr = msgs; 
 	for (i = 0; i < N;i++) 
	pthread_create(&tid, NULL, thread, &i); 
 	pthread_exit(NULL); 
} 

void *thread(void *vargp) 
{  
 	int myid = (*(int*)vargp}; 
 	static int cnt = 0;
 	printf("[%d]: %s (cnt=%d)\n", myid, ptr[myid], ++cnt); 
 	return NULL; 
} 

/*
A、	填表（是or否）：其中主线程叫m，其它两个线程叫p0、p1。i.m的意思表示i驻留在主线程的本地栈中
B、	根据A的填写，ptr、cnt、i、msgs、myid哪些是共享的？
参考知识点：
每个线程有自己的上下文：线程ID、栈、栈指针、程序计数器、条件代码、通用目的寄存器的值。
每个线程共享进程的：只读文本（代码）、读/写数据、堆、共享库代码和数据区、打开文件集合

变量实例	主线程引用否？	0线程引用否？		1线程引用否
ptr	        是			是					是
cnt		    否			是					是
i.m			是			否					否
msgs.m		是			是					是
myid.p0		否			是					否
myid.p1		否			否					是

*/