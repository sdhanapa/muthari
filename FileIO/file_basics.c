#include<stdio.h>


int main() {
    int ch;
    char buff[100];
    char name[50];
    int age;
    float score;

   // creating the file
   FILE *file = fopen("firstfile.log","a+");
    if(file == NULL) {
        perror("Error opening file");
        return 1;
    }
    // reading the file by single character
    while((ch = fgetc(file) ) != EOF){  // or use '\n' to read only one line
        putchar(ch);
    } 

  // reading the file by line
  
    if(fgets(buff,sizeof(buff), file) != NULL) {
        printf("\n output of line reading = %s",buff);
    }

    // reading structures data from file
    /* example: 
        Asha 10 22.45
        Banu 100 1.33
        chandini 12 5.44
    */
   while(fscanf(file, "%s %d %f",name, &age, &score) != EOF) {
        printf("Name = %s, Age = %d, Score = %.2f\n",name,age,score);
    }
   //==============================================================
   //====================== Writing in the file ========================================
   
   FILE *wfile = fopen("writing_file.txt","a+");
   if(wfile == NULL) {
    perror("Error Opening the w file");
    return 0;
   }

   // write by single char 
   fputc('A',wfile);  

   // write the line  into file
   fputs(" hello how are you?",wfile);

   //write a formatted data into file
   fprintf(wfile, "Name : %s age : %d score %f","Shamala",100,100.4532);

   fclose(file);
   fclose(wfile);
    return 0;
}




/*
1) fopen returns the file pointer.
2) syntax: FILE *fopen(const char *name, const char *mode);
3) mode: 
    r - read only ( file must exist)
    w - write also (creates a new file or trucates an existing file)
    a - apending (creates the new file, if it doesn't exist)
    r+ - open for reading and writing ( file must exist)
    w+ - open for reading and writing (creates the new file mor trucates an existing file)
    a+ - open for reading and writing (creates a new file if it doesn't exist)
*/

