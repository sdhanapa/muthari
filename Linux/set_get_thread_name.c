#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<string.h> // strerror
#include<errno.h> //errno

// Write a C program to SET and GET thread Name.

void* threadfunction(void* arg){
    char* name = (char*)arg;
    char thread_buff[16];
    
    if(pthread_setname_np(pthread_self(),name) == 0){
        if(pthread_getname_np(pthread_self(),thread_buff,sizeof(thread_buff)) !=0 ) {
          fprintf(stderr,"Failed to get the thread name",strerror(errno));
        } else {
          printf("%s ID = %ld is running\n",thread_buff,pthread_self());
        }
    printf("%s is done\n",thread_buff);
    }
}


int main() {
    pthread_t threadID1,threadID2,threadID3;
    pthread_create(&threadID1,NULL,threadfunction,"Thread-1");
    pthread_create(&threadID2,NULL,threadfunction,"Thread-2");
    pthread_create(&threadID3,NULL,threadfunction,"Thread-3");
    sleep(1);
    pthread_join(threadID1,NULL);
    pthread_join(threadID2,NULL);
    pthread_join(threadID3,NULL);
    return 0;
}


/*
       #define _GNU_SOURCE             // See feature_test_macros(7) 
       #include <pthread.h>

       int pthread_setname_np(pthread_t thread, const char *name);
       int pthread_getname_np(pthread_t thread, char name[.size], size_t size);
       
       
       strerror(errno) return appropriate string error.
*/