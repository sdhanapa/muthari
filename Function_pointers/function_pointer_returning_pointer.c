#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Write a program for Function Pointer Returning a Pointer

//Funtion that returns pointer to a string
char* getMorning() {
    char *cptr = (char*)malloc(25 * sizeof(char));
    strcpy(cptr,"Good Morning Muthari");
    return cptr;
}

//Function that returns pointer to string
char* getEvening() {
    char *cptr = (char*)malloc(20 * sizeof(char));
    strcpy(cptr , "Good Evening Muthari");
    return cptr;
}


int main() {

    char *message = NULL;
    char* (*fptr)() = NULL;
    
    //Initializing to getMorning, that return pointer to string.
    fptr = getMorning;
    message = fptr(); // call getMorning() via function pointer
    printf("message 1 = %s\n",message);
    free(message); // free the allocated memory


    //Initializing to getEvening, that return pointer to string.
    fptr = getEvening;
    message = fptr(); // call getEvening() via function pointer
    printf("message 2 = %s\n",message);
    free(message); // free the allocated memory

    return 0;
}