#include <stdio.h>
#include <cs50.h>

//MAIN ROUTINE
int main(){

    //create a file pointer
    FILE *objectData = NULL;

    //open a text file for reading/writing/appending
    objectData = fopen("log_fgetc.txt", "r");     //point objectData to an readable log.txt
    char dataChar = fgetc(objectData);
    if(objectData == NULL){
        printf("Error: Null Pointer \n");
        return 1;
    }

    //all read operations are done, close the file pointer
    fclose(objectData);

    //print data character
    printf("dataChar (from fgetc): %c\n", dataChar);


    printf("\n");   //newline
    return 0;
}