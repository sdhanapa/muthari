#include <stdio.h>
// to count number of char in a file//
int main() {
    int counter = 0;
    int ch = 0;
    FILE *file = fopen("read_this_file.log","r");
    while ( (ch =fgetc(file) )!= EOF) {
        if(ch != ' '){
        counter++;
        }
    }
    printf("Number of char in the file is %d",counter);


}