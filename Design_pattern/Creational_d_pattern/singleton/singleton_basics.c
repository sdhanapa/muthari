#include<stdio.h>
#include<stdlib.h>

//Write the C program for Singleton Design Pattern.

//Singleton structure
typedef struct {
    int data;
}Singleton;


//Static variable to hold the singleton instance
static Singleton* Instance = NULL;

//Function to instantiate the Instance

Singleton* GetInstance(){
    if(Instance == NULL){
        Instance = (Singleton*)malloc(sizeof(Singleton));
            if(Instance == NULL){
                fprintf(stderr,"Failed memory allocation\n");
                exit(1);
            }
        Instance->data = 0;
    }
    return Instance;
}

void getData() {
    Singleton *gton = GetInstance();
    printf("GetData = %d\n",gton->data);
}

void setData(int info) {
    Singleton *ston = GetInstance();
    ston->data = info;
    printf("Singleton Data Set\n");
    return;
}


int main() {
    getData();
    setData(10);
    getData();
    return 0;
}