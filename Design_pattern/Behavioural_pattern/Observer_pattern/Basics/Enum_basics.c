#include <stdio.h>  

// Define an enum named 'Events' with three possible values
enum Events {
    event1,   // event1 will automatically be assigned the value 0
    event2 = 10,  // event2 is explicitly set to 10
    event3   // event3 will automatically be assigned the value 11 (10 + 1)
};

int main()
{
    // Check if event1 is equal to 0
    if(event1 == 0 ) {
        // If true, print "Hello World" to the console
        printf("enum1\n");
    }
   
    // Check if event2 is equal to 1
    if (event2 == 1){
        // This condition will not be true since event2 is set to 10, so it won't print
        printf("enum2");
    }

    // Check if event3 is equal to 11
    if(event3 == 11){
        // If true, print "enum3" to the console
        printf("enum3");
    }
   
    // End of main function
    return 0;
}
/* Note:
enum (short for "enumeration") is a user-defined data type that consists of a set of named integer constants. 
It provides a way to assign names to integral values, which can make code more readable and maintainable.
*/

