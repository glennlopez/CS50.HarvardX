#include <stdio.h>
#include <cs50.h>

int main(){

    //fopen a file with write-able param
    //FILE *dataPointer = fopen("log_fputc.txt", "w");

    //fopen a file with appendable-able param
    FILE *dataPointer = fopen("log_fputc.txt", "a");

    //put a character into that file
    fputc('b', dataPointer);

    printf("\n");   //new line
    return 0;
}