#include<stdio.h>
#include<iostream>
#include<pthread.h>
#include<string.h>

using namespace std;
pthread_key_t tsdKey1;
pthread_key_t tsdKey2;

void TsdDestruct(void* param) {
	
}

void* ThreadFunc1(void* param) {
	int i = 0;
	int* data = nullptr;
	//printf("\nstack size in thread1 - %d",pthread_attr_getstacksize(pthread_self()));
	while(i<500) {
		i++;
		data = (int*)pthread_getspecific(tsdKey1);
	    if(data == nullptr) {
		    printf("Alloacting the tsd specifi data thread 1 \n");
		    data = new int ;
		    *data = 101;
		    pthread_setspecific(tsdKey1,(void*)data);
	    }
	    printf("tsd data = %d in thread %u-  \n",*data,pthread_self());
		sched_yield();
	}
	
	return data;
}

void* ThreadFunc2(void* param) {
	int i = 0;
	char* data = nullptr;
	//printf("\nstack size in thread 2 - %d",pthread_attr_getstacksize(pthread_self()));
	while(i<500) {
		i++;
		data = (char*)pthread_getspecific(tsdKey1);
	    if(data == nullptr) {
		    printf("Alloacting the tsd specifi data thread 2 \n");
		    //data = new char[15];
			data = (char*) malloc(sizeof(char)*32);
		    strcpy(data,"Om Shree");
			sprintf(data, "Om Shree %d  ",102);
		    pthread_setspecific(tsdKey1,(void *)data);
	    }
	    printf("tsd data = %s in thread %u-  \n",data,pthread_self());
	   //printf("%s\n",data);
		sched_yield();
	}
	return (void*)data;
}

int main() {
	pthread_t threadId1,threadId2;
	pthread_key_create(&tsdKey1,TsdDestruct);
	pthread_key_create(&tsdKey2,TsdDestruct);
	pthread_attr_t attr;
	pthread_attr_init(&attr);
	int stackSize = -1;
	pthread_attr_setstacksize(&attr,1024*8);
	printf("\nstack size in thread1 - %d",stackSize);
	
	int id1 = pthread_create(&threadId1,&attr,ThreadFunc1,nullptr);
	int id2 = pthread_create(&threadId2,&attr,ThreadFunc2,nullptr);
	pthread_join(threadId1,nullptr);
	pthread_join(threadId2,nullptr);
	
	pthread_exit(nullptr);
	return 0 ;
}