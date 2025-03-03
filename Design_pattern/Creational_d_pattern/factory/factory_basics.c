#include<stdio.h>

//Write a C program to Factory design pattern for logging application in c

//Step 1: Define the interface
typedef struct {
    void (*log)(const char *message);
}logger;

//Step 2: Create different implementation for the interface
void logToConsole(const char *message){
    printf(" Log to Console data: %s\n",message);
}


void logToFile(const char *message){
    printf(" Log to File data: %s\n",message);
    FILE *file = fopen("LogToFile.log","a");
    if(file){
        fprintf(file,"File Log: %s\n",message);
        fclose(file);
    } else {
        printf("Error Opening the File\n");
    }
}

//Step 3: Implement the concrete ( that is instance for interface is made ready)
logger CreateConsoleLogger() {
    logger LoggerC;
    LoggerC.log = logToConsole;
    return LoggerC;
}

logger CreateFileLogger() {
    logger LoggerF;
    LoggerF.log = logToFile;
    return LoggerF;
}


//Define the Factory
typedef enum{
    LOG_CONSOLE,
    LOG_FILE
}LoggerType;

logger CreateLog(LoggerType LogType){
    switch(LogType) {
        case LOG_CONSOLE:
            return CreateConsoleLogger();
        case LOG_FILE:
            return CreateFileLogger();
        default :
            printf("Invalide Logger Type, Defaulting to Cosole Log\n");
            CreateConsoleLogger();
    }
}
int main() {
    logger consoleLog;
    consoleLog = CreateLog(LOG_CONSOLE); // creating instance //
    consoleLog.log("Please print it in Console, Yes.\n"); // use the instance created//
   
    logger fileLog;
    fileLog = CreateLog(LOG_FILE); // creating instance
    fileLog.log("Hare Krishna Thanks\n"); // using the instance
   
    return 0;
}
/*
Notes: Factory Pattern is choosed in following scenarios

1) when system needs to be implemented independent of how the objects are created or represented.
2) When the Creation of object needs to be centralized to avoid code duplication.
3) The type of object to be created is determined at Runtime.

Steps for implementing the factory Pattern
1) Define the interface
2) Create different implementation for the interface
3) Implement the concrete
4) Define the factory
5) Use the Factory
*/
