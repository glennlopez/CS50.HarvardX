#include<stdio.h>
#include<cs50.h>
#include<string.h>

//argument count, argument vector
int main(int argc, string argv[]){ //w2 lecture - 1:41:00
    if(argc != 2){
        //if argument is missing
        printf("Missing cmd argument\n");
        return 1;
    }
    
    //if argument exists 
    printf("Hello, %s\n", argv[1]);

    return 0; //To see error/return code: echo $?
} 
