#include<stdio.h>
#include<iostream>
#include<pthread.h>
#include <unistd.h>   

void* threadFun(void* param) {
	int i = 0;
	while(i<3) {
		printf("\nIn Thread");
		sleep(1);
		i++;
	}
	pthread_exit(nullptr);
}

int main() {
	pthread_t thid;
	int id = pthread_create(&thid, NULL, threadFun, NULL);

/* and if that succeeded, detach the newly created thread. */
    if (id == 0) {
        id = pthread_detach(thid);
    }
	int *status = nullptr;
	if ( pthread_join(thid,(void**)&status) == -1 ) {                                      
        perror("pthread_join failed");                                               
        return -1;                                                                    
    } 
	if(status != nullptr ) {
		if ( status == (int *)-1 )                                                     
            puts("From Mian thread was cancelled");                                                
        else                                                                           
            printf("thread was not cancelled status = %d",*status);   
		
		return 0;
		
	} else { // status == nullptr
		printf("\n pthread_join status null");
	}
	pthread_exit(nullptr);
	return 0;
}