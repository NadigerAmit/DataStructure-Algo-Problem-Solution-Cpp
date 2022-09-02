
/*
The below program demonstrates the usage of pthread_once  function , 
which will  make sure the particulate function is called only once per process irrespective 
of any number of threads whiten the same process calling the same routine.
*/
#include<stdio.h>

#include<iostream>
#include<pthread.h>
using namespace std ;

#define NUM_OF_THREADS 5 
pthread_once_t once_control = PTHREAD_ONCE_INIT;
int globalCounter =  0;


void IncreamentGolablevarFun() {
		globalCounter++;
	printf(" -- >  %s called %d times\n",__FUNCTION__,globalCounter);
}

void* ThreadFunction(void* param) {
	int status = 0;
	printf(" inside the Thread %u\n",pthread_self());
	status = pthread_once(&once_control,IncreamentGolablevarFun);
	//IncreamentGolablevarFun();
	pthread_exit(nullptr);
}


int main() {
	pthread_t threadIdArray[NUM_OF_THREADS];
	int       threadparm[NUM_OF_THREADS];
	int id ;
	int joinStatus = 0;
	
	for(auto i = 0;i<NUM_OF_THREADS ;i++) {
		threadparm[i] = i+100;
		id = pthread_create(&threadIdArray[i],nullptr,ThreadFunction, &threadparm[i]);
		if(id < 0) {
			printf("pthread_create failed, errno=%d", errno);                        
             exit(2);                                          
		}
	}
	
	int *threadJoinStatus = new int;
	for(auto i = 0;i<NUM_OF_THREADS ;i++) {
		joinStatus = pthread_join(threadIdArray[i],(void **)&threadJoinStatus);
		if(joinStatus < 0) {
			printf("pthread_join failed, errno=%d", errno);                        
             exit(2);                                          
		}
		if(threadJoinStatus != 0) {
			printf("bad thread status, thread %d, status=%d\n", i,                
                                                   threadJoinStatus);
		}
	}
	
	if(globalCounter != 1) {
		printf("IncreamentGolablevarFun is called more than , globalCounter=%d",globalCounter);
	} else {
		printf("\nIncreamentGolablevarFun is called exacly once pthread_once() worked fine , globalCounter=%d\n",globalCounter);
	}
	pthread_exit(nullptr);
	return 0;
}
