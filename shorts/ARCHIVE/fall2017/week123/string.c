#include<stdio.h>
#include<cs50.h>

int main(){
    
    printf("What is your name: ");
    
    string s = get_string();    //get_string() is a function in cs50.h
    printf("Hello, %s", s);
    
    printf("\n");
    return 0;
}       

//ref: https://stackoverflow.com/questions/41554334/implicit-declaration-of-function-get-string