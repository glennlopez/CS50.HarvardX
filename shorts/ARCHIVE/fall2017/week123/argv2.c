#include<stdio.h>
#include<cs50.h>
#include<string.h>

//argument count, argument vector
int main(int argc, string argv[]){ 
    
    for(int i = 0; i < argc; i++){
        for(int j = 0, n = strlen(argv[i]); j < n; j++){
            printf("%c\n", argv[i][j]); //w2 lecture - 1:38:45
        }
    }
    
    printf("\n");
    return 0;
} 