#include <stdio.h>

int main(){

    // create a pointer
    FILE *textfile;

    // set the file pointer to read sample.txt
    textfile = fopen("sample.txt", "a");
    if(textfile == NULL){
        return 1;
    }

    //fputc( <character>, <file pointer> )
    fputc('X', textfile);


    fclose(textfile);
    printf("\n");
    return 0;
}