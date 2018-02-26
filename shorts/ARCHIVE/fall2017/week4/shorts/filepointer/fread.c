#include<stdio.h>
#include<cs50.h>

int main(){

    //open a file via file pointer
    FILE *filePointer;
    char arr[50];
    size_t sz;

    filePointer = fopen("log_fread.txt", "r");
    if(filePointer == NULL){
        perror("filePointer");
        exit(1);
    }

    //fread(<buffer>, <size>, <qty>, <filepointer>)
    sz = fread(arr, sizeof(char), 50, filePointer);

    printf("%s",arr);

    //close file pointer
    fclose(filePointer);

    printf("\n");       //end of main
    return 0;
}