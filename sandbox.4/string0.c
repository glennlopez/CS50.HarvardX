#include<stdio.h>
#include<cs50.h>
#include<string.h>

int main(){
     
    string s = get_string();
    for(int i = 0; i < strlen(s); i++){
        printf("%c", s[i]);
    }
    printf("\n");

    
    return 0;
}