#include<stdio.h>
#include<cs50.h>
#include<string.h>

//argument count, argument vector
int main(int argc, string argv[]){ 
    
    for(int i = 0; i < argc; i++){
        printf("%s\n", argv[i]);
    }
    
    return 0;
} 