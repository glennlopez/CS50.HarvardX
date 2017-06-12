//http://docs.cs50.net/problems/caesar/caesar.html
#include<stdio.h>
#include<cs50.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

//prototypes
char cypher(char, string);

//global variables
int keyCounter = 0;


//MAIN ROUTINE
int main(int argc, string argv[]){
    
    //argument error checking
    if(argc != 2){
        printf("Usage: %s k\n", argv[0]);
        return 1;
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
char cypher(char cin, string key){
    
    if(isupper(cin)){   //ascii upercase starts at 65
        //zero the character (index it)
        cin -= 65;
        
        //cypher the zeroed character using key
        cin = (cin + key) % 26;
        
        //un-zero the cyphered character into cin
        cin += 65;
    }
    if(islower(cin)){   //ascii lowercase starts at 97
        //zero the character (index it)
        //cin -= 97;
        
        //cypher the zeroed character using key
        //cin = (cin + key) % 26;
        
        //un-zero the cyphered character into cin
        //cin += 97;
    }
    
    printf("Keyword: %s KeyCounter: %i\n", key, keyCounter); // debug
    keyCounter++;
    return cin;
}

