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






/*  
    Password Generator Subroutine
    Description: brute forces DES hash 
    Dependencies: crypt(), isMatching()
*/
string keyGen(void){ 
    
    string password = "???";
    genHash = crypt(password, salt);

    //do{

        char key[5];

        key[0] = '@'; key[1] = '\0';
        for(int i = 0; key[0] != '{'; i++){
            key[0] += 1;

            password = key;
            genHash = crypt(password, salt);

            if(isMatching(usrHash, genHash)){
                return password;
            }


            key[1] = '@'; key[2] = '\0';
            for(int j = 0; key[1] != '{'; j++){
                key[1] += 1;

                password = key;
                genHash = crypt(password, salt);

                if(isMatching(usrHash, genHash)){
                    return password;
                }

                key[2] = '@'; key[3] = '\0';
                for(int k = 0; key[2] != '{'; k++){
                    key[2] += 1;

                    if(isMatching(usrHash, genHash)){
                        return password;
                    }

                    key[3] = '@'; key[4] = '\0';
                    for(int k = 0; key[3] != '{'; k++){
                        printf("%s\n", key);
                        key[3] += 1;

                        if(isMatching(usrHash, genHash)){
                            return password;
                        }   
                    }
                }
            }
        }

        



    //}while( !(isMatching(usrHash, genHash)) );


    return password;
}






/*  
    String Compare Subroutine
    Description: compares each char in a string and returns true if similar
    Dependencies: none
*/
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