#include <stdio.h>
/*
    Ref used:
        - https://www.tutorialspoint.com/c_standard_library/c_function_fseek.htm
        - https://www.cs.drexel.edu/cgi-bin/manServer.pl/putc.3
*/

int main(){

    // create a pointer
    FILE *textfile;

    // set a file pointer to read sample.txt
    textfile = fopen("sample.txt", "r+");
    if(textfile == NULL){
        return 1;
    }


    // places a char in ch from a file pointer until EOF
    char ch;
    while( (ch = fgetc(textfile)) != EOF ){
        // modifies . to a !
        if(ch == '.'){ // look for any instances of '.'
            fseek(textfile, -1, SEEK_CUR); // set cursor back 1 char
            fputc('!', textfile);   // put ! in the pos of the cursor
        }
    }


    fclose(textfile);
    printf("\n");
    return 0;
}