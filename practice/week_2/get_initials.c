#include <stdio.h>
#include <cs50.h>
#include <ctype.h>

/* 
    Track: 10min in the video
    Make a program that takes a user input (name) and converts it into 
    an initial.
*/

int main(){

    printf("Type your name: ");
    string uName = get_string();

    //calculate the number of chars to use for initials variable
    int nameSpace = 1;
    for(int i = 0; uName[i] != '\0'; i++){
        if(uName[i] == ' '){ 
            //if( isupper(uName[i + 1]) ){ //<--- this will not work if the name is in lower case
                nameSpace++;
            //}
        }
    }

    char initials[nameSpace + 1];
    initials[0] = uName[0];
    for(int i = 0; uName[i] != '\0'; i++){
        if(uName[i] == ' '){ 
                initials[i] = uName[i+1];
        }
    }
    initials[nameSpace + 1] = '\0'; //add a null terminator at the end

    //debug
    printf("Number of initials: %i\n", nameSpace);

    //print out variables
    printf("uName: %s\n", uName);
    printf("\n");

    printf("Initials: ");
    for(int i = 0; initials[i] != '\0'; i++){
        printf("%c\n", initials[i]);
    }

    return 0;
}