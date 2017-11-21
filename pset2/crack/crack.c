//compile using: clang -ggdb3 -O0 -std=c11 -Wall -Werror -Wshadow crack.c -lcrypt -lcs50 -lm -o crack
#define _XOPEN_SOURCE
#include <unistd.h>
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

//prototypes
bool isMatching(char[], char[]);
string keyGen(void);

//global variables
char salt[2];
char usrHash[20];
string genHash;


int main(int argc, string argv[]){


    //get command-line arguments
    if (argc != 2){
        printf("Error: Invalid argument!\n");
        return 1;
    }

    //extract information from user input (key length, hash, salt)
    unsigned int charCnt = 0;
    for(int i = 0; argv[1][i] != '\0'; i++){
        usrHash[i] = argv[1][i];
        charCnt++;
    }
    salt[0] = argv[1][0];
    salt[1] = argv[1][1];

    //check if matching
    //isMatching(usrHash, genHash);


    printf("Password: %s\n", keyGen());





    //debug output - usrHash string
    printf("Input: ");
    for(int i = 0; usrHash[i] != '\0'; i++){
        printf("%c", usrHash[i]);
    }
    printf("\n");

    printf("Salt: ");
    for(int i = 0; salt[i] != '\0'; i++){
        printf("%c", salt[i]);
    }
    printf("\n");






    printf("\n"); //newline
    return 0;
}






string keyGen(void){ string password = "???";

    do{
        password = "rofl";
        //hash generator
        genHash = crypt(password, salt);

    }while( !(isMatching(usrHash, genHash)) );

    return password;
}






//Checks to see if strings match
bool isMatching(char inputHash[], char generatedHash[]){

    //count character length
    unsigned int inputLen = 0;
    for(int i = 0; inputHash[i] != '\0'; i++){
        inputLen++;
    }
    unsigned int generatedLen = 0;
    for(int i = 0; generatedHash[i] != '\0'; i++){
        generatedLen++;
    }

    //check string length for missmatch
    if( !(inputLen == generatedLen) ){
        return false;
    }

    //check char for missmatch
    for(int i = 0; i < inputLen; i++){
        if(inputHash[i] != generatedHash[i]){
            return false;
        }
    }

    //return true if everything is the same
    return true;
}