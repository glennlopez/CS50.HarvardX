#include <stdio.h>

/*
    https://www.youtube.com/watch?v=8nIilb2kiSU
*/

int main(){

    // create a pointer
    FILE *textfile;

    // set the file pointer to read sample.txt
    textfile = fopen("sample.txt", "r");
    if(textfile == NULL){
        return 1;
    }

    char tempString[150];

    while(!feof(textfile)){ //iterate to the end of file
        fgets(tempString, 150, textfile);
        puts(tempString);
    }

    printf("\n");
    return 0;
}