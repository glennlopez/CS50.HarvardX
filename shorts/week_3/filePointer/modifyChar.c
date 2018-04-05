#include <stdio.h>
#include <cs50.h>
/*
    Ref used:
        - https://www.tutorialspoint.com/c_standard_library/c_function_fseek.htm
        - https://www.cs.drexel.edu/cgi-bin/manServer.pl/putc.3
*/

int main(){
    //user defined parameters
    char a = get_char("Change: ");
    char b = get_char("To: ");

    // create a pointer
    FILE *textfile;

    // set a file pointer to read sample.txt
    textfile = fopen("sample.txt", "r+");
    if(textfile == NULL){
        return 1;
    }


    // iterate through every char until EOF
    char ch;
    while( (ch = fgetc(textfile)) != EOF ){
        // modifier
        if(ch == a){    // looks for instances of var a
            fseek(textfile, -1, SEEK_CUR);
            fputc(b, textfile); // replaces var a with var b
        }
    }


    fclose(textfile);
    printf("\n");
    return 0;
}