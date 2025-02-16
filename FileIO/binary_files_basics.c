#include<stdio.h>

//Write a C program to write a binary file and then read and display its contents in hexadecimal format.

int main() {
    ////================writing binary file==================
    FILE *filedes = fopen("first_binary_file.bin","wb"); // Open binary file in write mode
    if(filedes == NULL) {
        perror("Error opening file");
        return 1;
    }

    unsigned char wdata[] = {11,12,13,14,15};
    unsigned char rdata[100];
    int i;
    size_t write_status = fwrite(wdata,sizeof(unsigned char),sizeof(wdata),filedes); // Write data to the file
    if(write_status) {
        printf("Binary file is writen successfully, %d \n",write_status);
    }
    for( i = 0;i<write_status;i++) {
    printf("written data to binry file : %02x\n",wdata[i]);
    }
    fclose(filedes);

    //================reading binary file==================
    filedes = fopen("first_binary_file.bin","rb"); // Open binary file in write mode
    if(filedes == NULL) {
        perror("Error reading file");
        return 1;
    }
    size_t read_status = fread(&rdata,sizeof(unsigned char),100,filedes);
    for( i = 0;i<read_status;i++) {
    printf("read data from binry file : %02X\n",rdata[i]); // printing in loop for each byte of binary data in hexadecimal format.
    }
    fclose(filedes);
    return 0;
}



/*binary files contain human non-readable format. 
Binary files can contain any kind of data, that 
can be used for storing data such as audio, images 
or compiled program,and they require specific 
handling when reading and writing.

       size_t fread(void ptr[restrict .size * .n],
                    size_t size, size_t n,
                    FILE *restrict stream);

fread() reads n items of data, each 'size' bytes long, 
from the 'stream' pointed by stream, storing them from the location given by ptr.


       size_t fwrite(const void ptr[restrict .size * .n],
                    size_t size, size_t n,
                    FILE *restrict stream);
fread() writes n items of data, each 'size' bytes long, 
to the 'stream' pointed by stream, obtaing them from the location given by ptr.

On success, returns number of items read or written.                    
*/