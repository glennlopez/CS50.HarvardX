#include <cs50.h>
#include <stdio.h>
#include <ctype.h>

#define MAX_CHAR 4

/*
    Takes users input (full name), and turns it
    into an initial by placing new chars in a new string.
*/

int main(){

    printf("Name: ");
    string uName = get_string();
    char initials[MAX_CHAR];

    //determines initials using uppercase (letter AND spaces) patern
    int initial_counter = 0;
    for(int i = 0; uName[i] != '\0'; i++){
        if( (isupper(uName[i])) && ( (uName[i - 1] == ' ') || (i == 0) ) ){
            initials[initial_counter] = uName[i];
            initial_counter++;
        }

        //user input error checking
        if(initial_counter >= 4){
            printf("Error: User name is too long!\n");
            return 1;
        }
        if(initial_counter == 0){
            printf("Error: User name formatting error.\n");
            return 1;
        }
    }
    initials[initial_counter] = '\0'; //makes sure null terminator is in the last array always

    //print out
    printf("uName: %s\n", uName);
    printf("initials: %s\n", initials);

    printf("\n");
    return 0;
}