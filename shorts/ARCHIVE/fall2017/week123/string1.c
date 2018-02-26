#include<stdio.h>
#include<cs50.h>
#include<string.h>

int main(){
     
    string s = get_string();
    for(int i = 0, n = strlen(s); i < n; i++){
        printf("%c", s[i]);
    }
    printf("\n");

    
    return 0;
} 