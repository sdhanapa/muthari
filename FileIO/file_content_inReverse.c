#include <stdio.h>
#include <string.h>

//Write a program to display the contents of a file in reverse order.

int main() {
    char buff[100];  // Temporary buffer for reading lines from the file
    char tmp[100];   // Larger buffer to hold the entire contents of the file
    int i,j,k =0;

    // Open file for reading and check for errors
    FILE *file = fopen("read_this_file.log","r+");
    if(file == NULL) {
        perror("Error open File");
        return 0;
    }

    // Read the file line by line and store it in buff 
    while(fgets(buff,sizeof(buff),file) != NULL) {
        // Copy characters from buff to tmp
        for(j=i;j<i+strlen(buff);j++) {
            if(j< sizeof(tmp)-1) { // Avoid buffer overflow in tmp
            tmp[j] = buff[k];
            }
            k++;
        }
        k=0;
        i = strlen(buff);
    }

    tmp[j] = '\0'; // Null-terminate the string in tmp
    printf("Data in the file = %s\n\nReverse of the data is = ",tmp);

    // Reverse printing loop
    for(int a= strlen(tmp)-1; a >= 0;a--) {
        printf("%c",tmp[a]);
    }

    fclose(file); // Close the file
    return 1;
}