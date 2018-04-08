#include <stdio.h>
#include <cs50.h>

#define MAX_CHAR 150

int main(){

    // create a pointer
    FILE *textfile;

    // set a file pointer to read sample.txt
    textfile = fopen("sample.txt", "r+");
    if(textfile == NULL){
        return 1;
    }

    //fread(<buffer>, <size>, <qty>, <filepointer>)
    /* example:
        int arr[10]; //<-- memory on the stack
        int *arr = malloc(sizeof(int) * 10); //<-- on the heap
        fread(arr, sizeof(int), 10, ptr);
    */

    //read data and store to buffer
    char *buffer = malloc(sizeof(char) * MAX_CHAR);
    fread(buffer, sizeof(char), MAX_CHAR, textfile);




    //print out buffer
    for(int i = 0; i < MAX_CHAR; i++){
        printf("%c", buffer[i]);
    }
    printf("\n");





    fclose(textfile);
    printf("\n");
    return 0;
}