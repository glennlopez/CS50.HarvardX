//http://docs.cs50.net/problems/vigenere/vigenere.html
//https://www.guballa.de/vigenere-solver
#include<stdio.h>
#include<cs50.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

#define ASCII_LWRCASE_INDEX 97
#define ASCII_UPRCASE_INDEX 65
#define A_TO_Z 26
#define KEY_SIZE strlen(key)

char cipher(char, string);
int charIndex = 0;


//MAIN ROUTINE
int main(int argc, string argv[]){
    
    //argument error checking
    if(argc != 2){
        printf("Usage: %s k\n", argv[0]);
        return 1;
    }
    else{
        for(int i = 0, n = strlen(argv[1]); i < n; i++){
            if(!(isalpha(argv[1][i]))){
                printf("Usage: %s k\n", argv[0]);
                return 1;
            }
        }
    }
    
    //get user-key
    string key = argv[1];
    
    //get user-plaintext
    printf("plaintext: ");
    string s = get_string();
    
    //encipher using user-key
    for(int i = 0, n = strlen(s); i < n; i++){
        s[i] = cipher(s[i], key);
    }
    
    //print ciphered string using key
    printf("ciphertext: %s\n", s);

    return 0; 
} 


//VIGENERE CIPHER SUBROUTINE
char cipher(char cin, string key){ int keyIndex = '?';

    //remove ascii from keyIndex (so a or A = 0) based on uppercase or lowecase
    if(islower(key[charIndex % KEY_SIZE])){
        keyIndex = key[charIndex % KEY_SIZE] - ASCII_LWRCASE_INDEX;
    }
    else{
        keyIndex = key[charIndex % KEY_SIZE] - ASCII_UPRCASE_INDEX;
    }
    
    //shift character by keyIndex
    if(isupper(cin)){  
        cin -= ASCII_UPRCASE_INDEX;         //remove ascii from char (so A = 0)
        cin = (cin + keyIndex) % A_TO_Z;    //add keyIndex to char
        cin += ASCII_UPRCASE_INDEX;         //add ascii back to char
        charIndex++;                        //increment to the next character
    }
    if(islower(cin)){ 
        cin -= ASCII_LWRCASE_INDEX; 
        cin = (cin + keyIndex) % A_TO_Z; 
        cin += ASCII_LWRCASE_INDEX;
        charIndex++;
    }
    
    return cin;
}

