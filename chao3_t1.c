/*
        PV操作实现 单生产者单消费者
*/

#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
#include<stdlib.h>
#define buffsize 25

//缓冲区定义
typedef struct{
        int *buf; //缓冲数组
        int n;
        int front;
        int rear;
        sem_t mutex;
        sem_t empty;
        sem_t full;
}sbuf_t;

sbuf_t sp;
void p(sem_t * s);
void v(sem_t * s);
void sbuf_init(sbuf_t *sp,int n);
void sbuf_insert(sbuf_t *sp,int item);
void *producer(void *spp);
void sbuf_remove(sbuf_t *sp);
void * consumer(void *spp);

int main(){
        pthread_t pro,con;
        sbuf_init(&sp,buffsize);
        pthread_create(&pro,NULL,&producer,NULL);
        pthread_create(&con,NULL,&consumer,NULL);
        pthread_join(pro,NULL);
        pthread_join(con,NULL);
}
/*
typedef struct{
        sem_t mutex;
        sem_t empty;
        sem_t full;
}ssem_t;
*/
//缓冲区初始化
void p(sem_t * s){
        if(sem_wait(s) < 0)
                printf("fatal error:P Error");
}

void v(sem_t * s){
        if(sem_post(s) < 0)
                printf("fatal error:V Error");
}
void sbuf_init(sbuf_t *sp,int n){
        sp->buf =(int *)calloc(n,sizeof(int));
        if(sp->buf == NULL)
                printf("fatal error:calloc error");
        sp->front = 0;
        sp->rear  = 0;
        sp->n = n;
        sem_init(&sp->mutex,0,1);
        sem_init(&sp->empty,0,buffsize);
        sem_init(&sp->full,0,0);
        printf("ok! n:%d front:%d rear:%d\n",sp->n,sp->front,sp->rear);
}

/*
//信号量初始化
void ssem_init(ssem_t *ss,int n){
        sem_init(&ss->mutex,0,1);
        sem_init(&ss->empty,0,buffsize);
        sem_init(&ss->full,0,0);
}
*/

void sbuf_insert(sbuf_t *sp,int item){
        p(&sp->empty);
        p(&sp->mutex);
        sp->buf[ (++(sp->rear)) % (sp->n) ] = item;
        printf("正在生产%d,front:%d,rear:%d\n",item,sp->front,sp->rear);
        v(&sp->mutex);
        v(&sp->full);
}
void *producer(void *spp){
        int i;
        for(i=0;i<20;i++){
                sbuf_insert(&sp,i);
        }
        return NULL;
}

void sbuf_remove(sbuf_t *sp){
        int item;
        p(&sp->full);
        p(&sp->mutex);
        item = sp->buf[ (++(sp->front)) % (sp->n) ];
        printf("正在消费第%d,front:%d,rear:%d\n",item,sp->front,sp->rear);
        v(&sp->mutex);
        v(&sp->empty);
}
void * consumer(void *spp){      
        int i;
        for(i=0;i<20;i++)
                sbuf_remove(&sp);
        return NULL;
}


