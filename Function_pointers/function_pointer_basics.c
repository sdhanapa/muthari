#include <stdio.h>

//Function pointers basics

//simple add function
int add(int a, int b){
    return a+b;
}

//simple sub function
int sub(int a, int b){
    return a-b;
}

void performOperation(int a,int b, int (*operation)(int,int)) {
    int result = operation(a,b);
    printf("result = %d\n",result);
}

void green(){
    printf("GO\n");
}

void amber(){
    printf("PREPARE\n");
}

void red(){
    printf("STOP\n");
}

int main() {
    //============Basic function pointer=============
    //Declaring the function pointer pointing nothing
    int (*operation)(int,int) = NULL;

    //Initializing funciton pointer to add function.
    operation = add;
    printf("Addition = %d\n",operation(1,2)); // Output: Addition: 3

    //Initializing funciton pointer to sub function.
    operation = sub;
    printf("subtration = %d\n",operation(1,2)); // Output: Addition: 1

    //===============Callback function===============
    performOperation(1,4,add);

    //===============Function Table=============
    void (*traffic[])() = {
        green,
        amber,
        red
    };

    for(int i =0; i<3;i++) {
    traffic[i]();
    }

    return 0;
}