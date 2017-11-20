#include <cs50.h>
#include <stdio.h>

/*
    [] Accept a single command-line argument (hashed password)
        [] Print error if no argument or more than one argument is entered
        [] return 1 on error
    [] Assume passwords were hashed with DES crypt function
    [] Assume passwords are no longer than 4 characters
    [] Assume that each password is composed of alphabetical characters (upper and lower case)
*/



int main(int argc, string argv[]){

    //get command-line arguments
    if (argc != 2){
        printf("Error: Invalid argument!\n");
        return 1;
    }

    //count the number of character user inputs
    unsigned int charCnt = 0;
    for(int i = 0; argv[1][i] != '\0'; i++){
        charCnt++;
    }

    //allocate memory for hashed password
    char* hashPwd = malloc(sizeof(char) * charCnt);


    //debug output
    printf("Number of letters: %i \n", charCnt);


    printf("\n"); //newline
    return 0;
}