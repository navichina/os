/*
这个程序的预期结果是2*NITERS，但是结果会有多种。请利用信号灯及pv操作修改这个程序，使其达到预期
*/
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
void *thread(void *vargp);
volatile int cnt = 0; /* Counter */
 // volatile的作用：直接存取原始内存地址
sem_t mutex; //互斥信号量
int main(int argc, char **argv)
{
        int niters;
        pthread_t tid1, tid2;
        /* Check input argument */
        if (argc != 2) {
                printf("usage: %s <niters>\n", argv[0]);
                exit(0);
        }

        niters = atoi(argv[1]);
        /* Create threads and wait for them to finish */

        sem_init(&mutex,0,1);
        pthread_create(&tid1, NULL, thread, &niters);
        pthread_create(&tid2, NULL, thread, &niters);
        pthread_join(tid1, NULL);
        pthread_join(tid2, NULL);
        /* Check result */
        if (cnt != (2 * niters))
                printf("BOOM! cnt=%d\n", cnt);
        else
                printf("OK cnt=%d\n", cnt);
        exit(0);
}

 /* Thread routine */
void *thread(void *vargp)
{
        int i, niters = *((int *)vargp);
        for (i = 0; i < niters; i++)
        {
                sem_wait(&mutex);
                cnt++;
                sem_post(&mutex);
        }
        return NULL;
}
