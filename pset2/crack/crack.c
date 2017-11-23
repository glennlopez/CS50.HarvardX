//compile using: clang -ggdb3 -O0 -std=c11 -Wall -Werror -Wshadow crack.c -lcrypt -lcs50 -lm -o crack
#define _XOPEN_SOURCE
#include <unistd.h>
#include <cs50.h>
#include <stdio.h>

//prototypes
bool isMatching(string inputHash, string generatedHash);
bool findPassword(string usrHash, string generatedHash);

//global variables
char usrHash[20];
char salt[20];

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

    //string hashGenerated = crypt("zzzz", salt); //generates predicted 50fkUxYHbnXGw hash
    string hashGenerated = crypt("zy", "50"); //generates predicted 50fkUxYHbnXGw hash

    //FIXME: make the above "rofl" generate "AAAA" to "zzzz" while usrHash != hashGenerated

    findPassword(usrHash, hashGenerated);

    /* DEBUG
    if( isMatching(usrHash, hashGenerated) ){
        printf("Match!\n");
    }
    */



    //debug out
    printf("Hash in: %s (from cmd-line)\n", usrHash);
    printf("Hash out: %s (generated w/ salt:50)\n", hashGenerated);

    return 0;
}




/*  
    Find Password Subroutine
    Description: Brute forces hash generation to find a matching pair
    Dependencies: isMatching()
*/
bool findPassword(string usrHash, string generatedHash){

    string hashGenerated = crypt("zzzz", salt); //starting hash

    //generate next param for crypt() function
    //string a = "b";
    //z = 50s7QGTz4Jjzc
    //f = 50AWs/7oe6pkA
    //gg = 503ri32DnOw4o
    //xl = 50H4BMr9R1ey2
    //zy = 50AHc7mcjHmzk

    char key[5];

    //brute force 1 character
    key[0] = '@'; key[1] = '\0';
    for(int i = 0; key[0] != '{'; i++){
        
        key[0] += 1;
        hashGenerated = crypt(key, salt); 

        if( isMatching(usrHash, hashGenerated) ){
            printf("Password found: %s\n", key);
            return true;
        }
    }

    //brute force 2 characters
    key[0] = '@'; key[1] = '\0';
    for(int i = 0; key[0] != '{'; i++){
        key[0] += 1;

        key[1] = '@'; key[2] = '\0';
        for(int j = 0; key[1] != '{'; j++){
           
            key[1] += 1;
            hashGenerated = crypt(key, salt);

            if( isMatching(usrHash, hashGenerated) ){
                printf("Password found: %s\n", key);
                return true;
            }
        }
    }

    printf("Password not found! \n");
    return false;
}




/*  
    String Compare Subroutine
    Description: compares each char in a string and returns true if similar
    Dependencies: none
*/
bool isMatching(string inputHash, string generatedHash){

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