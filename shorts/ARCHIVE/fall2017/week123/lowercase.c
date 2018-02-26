#include<stdio.h>
#include<cs50.h>
#include<string.h>

int main(){
    
    for(char ascii = 'A'; ascii <= 'Z'; ascii++){
        printf("%c is lowercase %c\n", ascii, (ascii + 32));
    }
    
    return 0;
} 