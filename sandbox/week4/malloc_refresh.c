#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
//memcheck using: valgrind --tool=memcheck --leak-check=yes

/*
    Get user string input from stack
    memory and allocate it to heap memory
*/

int main(){

    //get string from user
    printf("User Input: ");
    char *usrString = get_string();

    //count the size of the string
    int usrStringSize = 0;
    int n = 0;
    while(usrString[n] != '\0'){
        usrStringSize++;
        n++;
    }

    //memory allocate to heap
    char *usrHeap = malloc(usrStringSize * sizeof(char));

    //copy string to heap memory
    for(int i = 0; i < usrStringSize; i++){
        usrHeap[i] = usrString[i];
    }

    //debug: count printf
    printf("usrStringSize: %i", usrStringSize);
    printf("\n");


    //debug: print out user string
    for(int i = 0; usrHeap[i] != '\0'; i++){
        printf("%c", usrHeap[i]);
        //printf("%c", *(usrHeap + 1));
    }
    printf("\n");

    //free heap memory
    free(usrHeap);



    return 0;
}