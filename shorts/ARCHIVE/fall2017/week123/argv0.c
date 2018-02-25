#include<stdio.h>
#include<cs50.h>
#include<string.h>

//argument count, argument vector
int main(int argc, string argv[]){ 
    
    if(argc == 3){
        printf("Hello, %s %s\n", argv[1], argv[2]);
    }
    else if(argc == 2){
        printf("Hello, %s\n", argv[1]);
    }
    else{
        printf("Hello, world\n");
    }
   
    printf("\n");
    return 0;
} 