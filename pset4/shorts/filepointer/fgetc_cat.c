#include <stdio.h>
#include <cs50.h>

//MAIN ROUTINE
int main(){ //FIXME: add commandline argument

    //create a file pointer
    FILE *objectData = NULL;

    //point objectData to an readable log.txt
    objectData = fopen("log_fgetc.txt", "r");   //FIXME: replace with commandline argument
    if(objectData == NULL){
        printf("Error: Null Pointer \n");
        return 1;
    }

    //print data from objectData
    char ch;
    while( (ch = fgetc(objectData)) != EOF ){
        printf("%c", ch);
    }
     printf("\n");  //new line

    //all read operations are done, close the file pointer
    fclose(objectData);


    printf("\n");   //new line
    return 0;
}