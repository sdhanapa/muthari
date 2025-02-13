#include <stdio.h>

//Write a program to return a function pointer

int add(int a,int b) {
    return a + b;
}

int sub(int a,int b) {
    return a-b;
}

//function to return a appropriate function pointer
int (*getOperation(int choi))(int,int) {
    switch(choi) {
        case 1: 
            printf("Addition  is choosed.\n");
            return add;
        case 2:
            printf("Subtraction is choosed.\n");
            return sub;
        default : 
            printf("Invalid choice\n");
            return NULL; // No operation to return
    }
    
}
int main() {
    int (*funcpointer)(int,int) = NULL; // Declaring function pointer.
    int choice = 0;
    int a,b;
    while(1) {
        printf("Enter the option, Choice 1 is for addition, Choice 2 is for Subtraction\n");
        scanf("%d",&choice);
        
        //Get the correct function pointer
        funcpointer = getOperation(choice);
        
        if(funcpointer) {
        printf("Enter the value ");
        scanf("%d %d",&a,&b);
        printf("result = %d\n",funcpointer(a,b));
        }
    }
    return 0;
}