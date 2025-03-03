#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

//function used to run the new thread
void* thread_create(void* arg) {
    int *ret = (int*)malloc(sizeof(int));
    ret =  (int*)arg;
    printf("new thread created.. arg = %d\n",*ret);
    return (void*)ret;
}

int main() {
    pthread_t TID;
    int data = 10;
    void *recieved_val;
    int *recv_val;
    int t_status = pthread_create(&TID,NULL,thread_create,&data); // fork point, where new thread is created.
    if(t_status != 0) {
        perror("Error Creating Thread..!");
        return 1;
    }
    
    t_status = pthread_join(TID,&recieved_val);
    recv_val = (int*)recieved_val;
    if(t_status != 0) {
        perror("Error Joining the main Thread..!");
        return 1;
    } 

    printf("Return value from the new thread is %d\n",*recv_val);
    
    return 0;
}