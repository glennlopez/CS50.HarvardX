//compile using: clang -ggdb3 -O0 -std=c11 -Wall -Werror -Wshadow crack.c -lcrypt -lcs50 -lm -o crack
#define _XOPEN_SOURCE
#include <unistd.h>
#include <cs50.h>
#include <stdio.h>

    //test hash
    //z = 50s7QGTz4Jjzc
    //f = 50AWs/7oe6pkA
    //gg = 503ri32DnOw4o
    //xl = 50H4BMr9R1ey2
    //zy = 50AHc7mcjHmzk
    //zyz = 50oi68XAsf0jA
    //xyz = 50yi70MN3ixyM
    //cat = 506RU8OAqwvXA
    //dog = 50Ecvq43taQ.I
    //CoW = 507dx548PpBLs
    //cow = 50ZYHbIgHblYI

//prototypes
bool isMatching(string, string);
bool findPassword(string usrHash);

//global variables
char usrHash[20];
char salt[20];



//MAIN ROUTINE
int main(int argc, string argv[]){

    //get command-line arguments
    if (argc != 2){
        printf("Error: Invalid argument!\n");
        return 1;
    }

    //extract information from cmd-line arg (key length, hash, salt)
    unsigned int charCnt = 0;
    for(int i = 0; argv[1][i] != '\0'; i++){
        usrHash[i] = argv[1][i];
        charCnt++;
    }
    salt[0] = argv[1][0];
    salt[1] = argv[1][1];

    //bruteforce hash for password
    findPassword(usrHash);

    return 0;
}




/*  
    Description: generates every possible hash to find a match and returns the key
    Dependencies: isMatching()
    Returns: True or False if password is found (for debugging)
*/
bool findPassword(string usrHash){ 
    
    string hashGenerated;  
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

    //brute force 3 characters
    key[0] = '@'; key[1] = '\0';
    for(int i = 0; key[0] != '{'; i++){
        key[0] += 1;

        key[1] = '@'; key[2] = '\0';
        for(int j = 0; key[1] != '{'; j++){
            key[1] += 1;

            key[2] = '@'; key[3] = '\0';
            for(int k = 0; key[2] != '{'; k++){
                
                key[2] += 1;
                hashGenerated = crypt(key, salt);

                //printf("%s\n", key);    //debug output

                if( isMatching(usrHash, hashGenerated) ){
                    printf("Password found: %s\n", key);
                    return true;
                }
            }
        }
    }

    //brute force 4 characters
    key[0] = '@'; key[1] = '\0';
    for(int i = 0; key[0] != '{'; i++){
        key[0] += 1;

        key[1] = '@'; key[2] = '\0';
        for(int j = 0; key[1] != '{'; j++){
            key[1] += 1;

            key[2] = '@'; key[3] = '\0';
            for(int k = 0; key[2] != '{'; k++){
                key[2] += 1;

                key[3] = '@'; key[4] = '\0';
                for(int k = 0; key[3] != '{'; k++){

                    key[3] += 1;
                    hashGenerated = crypt(key, salt);

                    //printf("%s\n", key);    //debug output

                    if( isMatching(usrHash, hashGenerated) ){
                        printf("Password found: %s\n", key);
                        return true;
                    }
                }
            }
        }
    }


    printf("Password not found! \n");
    return false;
}




/*  
    Description: compares each char in a string and returns true if similar
    Dependencies: none
    Returns: True or False if string matches char per char
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