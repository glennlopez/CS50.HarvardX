//http://docs.cs50.net/problems/caesar/caesar.html
#include<stdio.h>
#include<cs50.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

char cypher(char, int);

/*
    [x] get the key
    [x] get the plaintext
    [x] encipher
    [x] print ciphertext

*/


int main(int argc, string argv[]){
    
    //argument error checking
    if(argc != 2){
        printf("Usage: %s k\n", argv[0]);
        return 1;
    }
    
    //get user-key
    int key = atoi(&argv[1][0]);
    
    //get user-plaintext
    string s = get_string();
    
    //print ciphered string using key
    for(int i = 0, n = strlen(s); i < n; i++){
        s[i] = cypher(s[i], key);
    }
    
    printf("%s\n", s);


    return 0; 
} 



//CIPHER CHAR ROUTINE
char cypher(char cin, int key){
    
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
        cin -= 97;
        
        //cypher the zeroed character using key
        cin = (cin + key) % 26;
        
        //un-zero the cyphered character into cin
        cin += 97;
    }
    return cin;
}

