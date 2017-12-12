#include <stdio.h>
#include <cs50.h>

/*
    Uses command-line argument to put put a string of characters
    into a file
*/

int main(int argc, char *argv[]){

    if(argc != 2){
        printf("Error: improper argument!\n");
        return 1;
    }

    //fopen a file with appendable-able param
    FILE *dataPointer = fopen("log_fputc.txt", "a");

    //put command line argument to textfile
    for(int i = 0; argv[1][i] != '\0'; i++){//change NULL to EOF
        printf("%c", argv[1][i]);
        //fputs(argv, dataPointer);
    }

    //put a character into that file
    fputc('b', dataPointer);

    printf("\n");   //new line
    return 0;
}