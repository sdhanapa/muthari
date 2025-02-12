#include <stdio.h>

// Write a program to count the number of lines in a file. //
int main(){ 
    char buff[100];
    int counter =0;
    FILE *file = fopen("read_this_file.log","r");
    if(file == NULL) {
        perror("Error opening the file");
    }
    while(fgets(buff,sizeof(buff),file) != NULL) {
        counter++;
        printf("read by lines are = %s",buff);
    }
    printf("\nNumber of lines in the file is %d",counter);

    fclose(file);
    return 1;

}