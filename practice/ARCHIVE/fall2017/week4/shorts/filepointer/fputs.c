#include <stdio.h>
#include <cs50.h>

int main(){

    FILE *inputData = fopen("log_fputs.txt", "w");
    if(inputData == NULL){
        printf("Error! File poiunter is null\n");
        return 1;
    }

    //fputs puts string, fputc puts char
    fputs("I ate 55 pumpkins today.", inputData);
    fclose(inputData);

    printf("\n");
    return 0;
}