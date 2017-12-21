#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>

int main(){

    FILE *filePointer = fopen("fseek.txt", "w+");
    if(filePointer == NULL){
        printf("Error! File poiunter is null\n");
        return 1;
    }

    //original
    fputs("I ate 55 pumpkins today.", filePointer);

    //modified quantity
    fseek(filePointer, 5, SEEK_SET);
    fputs(" 10", filePointer);

    //modified day
    fseek(filePointer, 18, SEEK_SET);
    fputs("yesterday", filePointer);

    fclose(filePointer);

    printf("\n");
    return 0;
}