#include<stdio.h>

//Write a C program to return a pointer for chaining.

typedef struct {
    int data;
}Myobj;

Myobj* Init(Myobj* obj, int value){
    obj->data = value;
    return obj;
}

Myobj* add(Myobj* obj, int val) {
    obj->data += val;
    return obj;
}

Myobj* mul(Myobj* obj, int val){
    obj->data *= val;
    return obj;
}



int main(){
 Myobj obj;
 mul(add(Init(&obj,10),1),2);
 
 printf("output: %d",obj.data);
 return 0;  
}





/*
Notes: Function Chaining
Each function return the pointer to the same object of the common struct. This allows the next function in the chain to be called on the same object
*/
