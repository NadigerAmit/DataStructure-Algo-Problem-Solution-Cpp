#include<stdio.h>
#include<pthread.h>

pthread_mutex_t mutex;
pthread_cond_t cond;

void* threadFun1(void* param) {
    while(1) {
        pthread_mutex_lock(&mutex);
        printf("Om Shree Ganeshaya Namah\n");
	pthread_cond_signal(&cond);
	pthread_cond_wait(&cond,&mutex);
	pthread_mutex_unlock(&mutex);
    }
    pthread_exit(nullptr);
}
void* threadFun2(void* param) {
    while(1) {
         pthread_mutex_lock(&mutex);
         printf("Om Namah Shivaya\n");
	 pthread_cond_signal(&cond);
	 pthread_cond_wait(&cond,&mutex);
	 pthread_mutex_unlock(&mutex);
    }
      pthread_exit(nullptr);
}

int main() {
    int threadId1,threadId2;
    pthread_t id1,id2;
    pthread_mutexattr_t mutexAttr;
    pthread_mutexattr_settype(&mutexAttr, PTHREAD_MUTEX_NORMAL);
    pthread_mutex_init(&mutex,&mutexAttr);
    pthread_cond_init(&cond,nullptr);
    threadId1= pthread_create(&id1,nullptr,threadFun1,nullptr);
    threadId1= pthread_create(&id2,nullptr,threadFun2,nullptr);
    pthread_exit(nullptr);
    return 0;
}


