#include <stdio.h>
#include <stdlib.h>

// Write the C program for interfaces implementation


//Define the interfaces as struct containing the function pointer.
typedef struct {
    void (*start)(void);
    void (*stop)(void);
    void (*process)(int data);
}MyInterface;


// create different implmentation for the interfaces that matches the fnptr signature.

void startA(void){
    printf("Implementation A started.\n");
}
void stopA(void){
    printf("Implementation A Stopped.\n");
}
void ProcessA(int data){
    printf("Implementation A Processed data is %d.\n",data);
}


void startB(void){
    printf("Implementation B started.\n");
}
void stopB(void){
    printf("Implementation B Stopped.\n");
}
void ProcessB(int data){
    printf("Implementation B Processed data is %d.\n",data);
}



int main() {
    //Create instance of the interface for the implementation A
	/* Following is called Designated Initialization, alternate for this is
    MyInterface implB = { startB, stopB, processB };
    */
	
    MyInterface ImpA = {
    .start = startA,
    .stop = stopA,
    .process = ProcessA
    };
   
    //Use the interface
    ImpA.start();
    ImpA.process(40);
    ImpA.stop();
   
    //Create instance of the interface for the implementation B
    MyInterface ImpB = {
    .start = startB,
    .stop = stopB,
    .process = ProcessB
    };
   
    //Use the interface
    ImpB.start();
    ImpB.process(4000);
    ImpB.stop();    
   
    return 0;
}


 /* Following is called Designated Initialization, alternate for this is
    MyInterface implB = { startB, stopB, processB };
    */
