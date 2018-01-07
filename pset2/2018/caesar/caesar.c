//http://docs.cs50.net/problems/caesar/caesar.html
#include<stdio.h>
#include<cs50.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

char cypher(char, int);


//MAIN ROUTINE
int main(int argc, string argv[]){
    
    //argument error checking
    if(argc != 2){
        printf("Usage: %s k\n", argv[0]);
        return 1;
    }
    
    //get user-key
    int key = atoi(&argv[1][0]);
    
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



//CAESAR CIPHER SUBROUTINE
char cypher(char cin, int key){
    
    if(isupper(cin)){ 
        cin -= 65; cin = (cin + key) % 26; cin += 65;
    }
    if(islower(cin)){ 
        cin -= 97; cin = (cin + key) % 26; cin += 97;
    }
    
    return cin;
}

