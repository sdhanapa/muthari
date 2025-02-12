#include <stdio.h>

// Write a program to copy the contents of one file ("source.txt") to another file ("destination.txt"). //
int main(){ 
    char buff[100];
    int counter =0;
    FILE *sfile = fopen("read_this_file.log","r");
    FILE *dfile = fopen("dst_file.txt","w+");
    if(sfile == NULL) {
        perror("Error opening the source file");
    }
    else if(dfile == NULL) {
        perror("Error opening the dest file");
    }
    while(fgets(buff,sizeof(buff),sfile) != NULL) {
        fputs(buff,dfile);
        printf("read by lines are = %s",buff);
    }
    printf("\nNumber of lines in the file is %d",counter);

    fclose(sfile);
    fclose(dfile);
    return 1;

}