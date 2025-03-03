#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>

typedef struct Data { 
    int day;
    int month;
    int year;
}data;

//function used to run the new thread
void* thread_create(void* arg) {
    data *ret = (data*)arg;
    ret->day = 1;
    ret->month =1;
    ret->year = 1880;
    pthread_t new_thread = pthread_self();
    printf("new thread's ID = %ld\n",new_thread);
    return (void*)ret;
}

int main() {
    pthread_t TID;
    
    void *recieved_val = NULL;
    data recv_val;
    
    pthread_t main_thread = pthread_self();
    printf("main thread ID = %ld\n",main_thread);
    int t_status = pthread_create(&TID,NULL,thread_create,(void *)&recv_val); // fork point, where new thread is created.
    if(t_status != 0) {
        perror("Error Creating Thread..!");
        return 1;
    }
    
    t_status = pthread_join(TID,&recieved_val);

    if(t_status != 0) {
        perror("Error Joining the main Thread..!");
        return 1;





        
    } 
    
    
    printf("Return value from the new thread, at main thread PID = %ld \nDOB = %d/%d/%d",main_thread,recv_val.day,recv_val.month,recv_val.year);
    //free(recv_val);
    return 0;
}


/*
typedef is allias, useful for code readability, no need to write sruct each time.
*/