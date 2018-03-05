#include <stdio.h>
#include <cs50.h>

/*
    This program takes a user input get_string
    and copy it into heap memory
*/

int main(){
    int usrStr_size = 0;

    //ask user for string
    char *usrStr = get_string("User String: ");
    if(!usrStr){     //not enough memory
        return 1;
    }

    //print out user string + count string size
    printf("Stack Memory: ");
    for(usrStr_size = 0; usrStr[usrStr_size] != '\0'; usrStr_size++){
        printf("%c", usrStr[usrStr_size]);
    }
    printf("\n");

    //allocate heap memory
    char *usrStr_copy = malloc((usrStr_size + 1) * sizeof(char));
    if(!usrStr_copy){   //not enough memory
        return 1;
    }

    //copy user string into heap memory
    
    for(int i = 0; i < usrStr_size; i++){
        usrStr_copy[i] = usrStr[i];
    }
    
    //print out contents of heap memory
    printf("Heap Memory: ");
    for(int i = 0; usrStr_copy[i] != '\0'; i++){
        printf("%c", *(usrStr_copy + i));
    }
    printf("\n");

    return 0;
}