#include<stdio.h>
#include<cs50.h>
#include<string.h>
#include<ctype.h>   //toupper() & tolower()

int main(){
    
    string s = get_string();
    if(s != NULL){
        for(int i = 0, n = strlen(s); i < n; i++){
            if(s[i] > 97){
                printf("%c", s[i] - 32);
            }
            else{
                printf("%c", s[i]);     
            }
        }
        printf("\n");
    }
    
    return 0;
} 