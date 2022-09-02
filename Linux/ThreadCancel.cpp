                                                        
#include <errno.h>                                                              
#include <pthread.h>                                                            
#include <stdio.h>                                                              
#include <string.h>                                                             
#include <unistd.h>                                                             
                                                                                
int  thstatus;                                                                  
                                                                                
void * thread(void *arg)                                                        
{                                                                               
    puts("thread has started. now sleeping");                                      
    while (1)                                                                      
        sleep(1);
    pthread_exit(nullptr);                                                                  
}                                                                               
                                                                                
main(int argc, char *argv[])                                                    
{                                                                               
    pthread_t      thid;                                                           
    void           *status;                                                        
                                                                                
    if ( pthread_create(&thid, NULL, thread, NULL) != 0) {                         
       perror("pthread_create failed");                                             
       return -1;                                                                     
    }                                                                              

                                                                            
    if ( pthread_cancel(thid) == -1 ) {                                            
        perror("pthread_cancel failed");                                             
        return -1;                                                                  
    }   

                                                                                
    if ( pthread_join(thid, &status)== -1 ) {                                      
        perror("pthread_join failed");                                               
        return -1;                                                                    
    }                                                                              
                                                                                
    if ( status == (int *)-1 )                                                     
        puts("From Mian thread was cancelled");                                                
    else                                                                           
        puts("thread was not cancelled");                                            
                                                                                
 return 0;                                                                       
}                                                                               