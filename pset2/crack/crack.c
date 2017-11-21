#include <cs50.h>
#include <stdio.h>

/*
    [x] Accept a single command-line argument (hashed password)
        [x] Print error if no argument or more than one argument is entered
        [x] return 1 on error
    [1] Assume passwords were hashed with DES crypt function
    [!] Assume passwords are no longer than 4 characters
    [!] Assume that each password is composed of alphabetical characters (upper and lower case)

    Topics covered in Week 2:
        - Functions, Variable scope, Array, Command-line arguments, Magic Numbers
        - Strings, Ascii, error codes
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

    //allocate memory for hashed password based on character count
    char* hashPwd = malloc(sizeof(char) * charCnt);

    //place argument vector into heap-memory for manipulation
    for(int i = 0; i < charCnt; i++){
        hashPwd[i] = argv[1][i];
    }






    //debug output
    printf("Number of letters: %i \n", charCnt);
    printf("Heap-memory (hashPwd): ");
    for(int i = 0; i < charCnt; i++){
        printf("%c", hashPwd[i]);
    }
    printf("\n");

    printf("\n"); //newline
    return 0;
}