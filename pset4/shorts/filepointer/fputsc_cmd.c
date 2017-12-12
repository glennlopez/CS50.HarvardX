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
    FILE *dataPointer = fopen("log_fputsc_cmd.txt", "a");

    //copy argv to string
    char *usrStr[20];
    for(int i = 0; argv[1][i] != '\0'; i++){
        usrStr[i] = &argv[1][i];
    }

    //char test[20] = "testing";

    //debug printout
    for(int i = 0; usrStr[i] != '\0'; i++){
        printf("%s", usrStr);
    }

    fclose(dataPointer);


    printf("\n");   //new line
    return 0;
}