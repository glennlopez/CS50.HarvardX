#include <stdio.h>
#include <cs50.h>

//MAIN ROUTINE
int main(int argc, char *argv[]){ //FIXME: add commandline argument

    //get cmdline argument from user
    if(argc != 2){
        printf("Error: Improper command line argument.\n");
        return 1;
    }


    //create a file pointer
    FILE *objectData = NULL;

    //point objectData to an file specified by the cmdline argument
    objectData = fopen(argv[1], "r");
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