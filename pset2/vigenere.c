//http://docs.cs50.net/problems/vigenere/vigenere.html
//https://www.guballa.de/vigenere-solver
#include<stdio.h>
#include<cs50.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

char cypher(char, string);
int keyCounter = 0;


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
        s[i] = cypher(s[i], key);
    }
    
    //print ciphered string using key
    printf("ciphertext: %s\n", s);

    return 0; 
} 


//VIGENERE CIPHER SUBROUTINE
char cypher(char cin, string key){ int vKey = '?';

    //index the user key
    if(islower(key[keyCounter % strlen(key)])){
        vKey = key[keyCounter % strlen(key)] - 97;
    }
    else{
        vKey = key[keyCounter % strlen(key)] - 65;
    }
    
    //index the user input
    if(isupper(cin)){  
        cin -= 65; cin = (cin + vKey) % 26; cin += 65;
        keyCounter++;
    }
    if(islower(cin)){ 
        cin -= 97; cin = (cin + vKey) % 26; cin += 97;
        keyCounter++;
    }
    
    return cin;
}

