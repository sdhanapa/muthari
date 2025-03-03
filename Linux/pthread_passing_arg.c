#include<stdio.h>
#include<pthread.h>

//function used to run the new thread
void* thread_create(void* arg) {
    int result = *(int*)arg;
    printf("new thread created.. arg = %d\n",result);
}

int main() {
    pthread_t TID;
    int data = 10;
    int t_status = pthread_create(&TID,NULL,thread_create,&data); // fork point, where new thread is created.
    if(t_status != 0) {
        perror("Error Creating Thread..!");
        return 1;
    }
    
    t_status = pthread_join(TID,NULL);
    if(t_status != 0) {
        perror("Error Joining the main Thread..!");
        return 1;
    }    
    return 0;
}