#include <stdio.h>

int main(){

    // create a pointer
    FILE *textfile;

    // set the file pointer to read sample.txt
    textfile = fopen("sample.txt", "r");
    if(textfile == NULL){
        return 1;
    }

    // iterate through textfile
    char ch;
    while( (ch = fgetc(textfile)) != EOF ){ //store fgetc from pointer to a char
        printf("%c", ch);
    }



    fclose(textfile);
    printf("\n");
    return 0;
}