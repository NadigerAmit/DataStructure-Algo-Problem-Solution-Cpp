#define _REENTRANT
#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
#include<sched.h>


sem_t sem;
sem_t sem1;

void* threadFun1(void* param) {
    int val = 0 ;
    while(1) {
	    sem_wait(&sem);    
        printf("Om Shree Ganeshaya Namah\n");
	   // sem_post(&sem);
    }
      pthread_exit(nullptr);
}

/*
void* threadFun1(void* param) {
    while(1) {
	sem_wait(&sem);    
        printf("Om Shree Ganeshaya Namah\n");
	sem_post(&sem1);

    }
    pthread_exit(nullptr);
}
*/


void* threadFun2(void* param) {
    int val = 0 ;
    while(1) {
   	     sem_getvalue(&sem,&val);
         printf("\n val = %d\n",val);
         if(val<=0)  {	 
             printf("Om Namah Shivaya\n");
	     sem_post(&sem);
	 } else  {
             printf("Yielding the thread\n");
	     sched_yield();
	   //  pthread_yield();
	 } 
    }
      pthread_exit(nullptr);
}

/*
void* threadFun2(void* param) {
    while(1) {
        sem_wait(&sem1);
	    printf("Om Namah Shivaya\n");
	    sem_post(&sem);
    }
    pthread_exit(nullptr);
}
*/

int main() {
    int threadId1,threadId2;
    pthread_t id1,id2;
    sem_init(&sem,0,1);
    sem_init(&sem1,0,0);
    threadId1= pthread_create(&id1,nullptr,threadFun1,nullptr);
    threadId1= pthread_create(&id2,nullptr,threadFun2,nullptr);
    pthread_exit(nullptr);
    return 0;
}


