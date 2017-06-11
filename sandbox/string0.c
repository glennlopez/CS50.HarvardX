https://cs50.stackexchange.com/questions/2804/what-does-if-s-null-do
#include<stdio.h>
#include<cs50.h>
#include<string.h>

int main(){ //CTRL + D = NULL
     
    string s = get_string();
    if(s != NULL){
        for(int i = 0; i < strlen(s); i++){
        printf("%c", s[i]);
        }
    }
    else{
        printf("NULL character detected.\n");
    }
    printf("\n");

    
    return 0;
} 