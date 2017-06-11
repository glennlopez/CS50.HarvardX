#include<stdio.h>
#include<cs50.h>
#include<string.h>
#include <ctype.h>

int main(void){
    
    string s = get_string();
    
    //get first initial
    if(s[0] >= 'A'){
        printf("%c", toupper(s[0]));
    }
    
    //get every other initial
    for(int i = 0, n = strlen(s); i < n; i++){
        if( (s[i] == ' ') && (s[i+1] >= 'A') ){
            printf("%c", toupper(s[i+1]));
        }
    }

    printf("\n");
    return 0; 
} 
