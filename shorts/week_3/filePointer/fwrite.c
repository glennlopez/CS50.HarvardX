#include <stdio.h>
#include <cs50.h>

#define MAX_CHAR 500

int main(){

    // create a pointer
    FILE *textfile;

    // set a file pointer to read sample.txt
    textfile = fopen("sample.txt", "r+");
    if(textfile == NULL){
        return 1;
    }

    //read data and store to buffer
    char *buffer = malloc(sizeof(char) * MAX_CHAR);
    fread(buffer, sizeof(char), MAX_CHAR, textfile);

    /*
        Using fwrite();
            - fwrite(<buffer>, <datatype size>, <qty>, <file pointer>);
    */

    //replace every instance of Glenn with Lopez
    char w_buffer[] = "Lopez";
    int cur_pos = 0;
    for(int x = 0; buffer[x] != '\0'; x++){
        if(
            buffer[x + 0] == 'G' &&
            buffer[x + 1] == 'l' &&
            buffer[x + 2] == 'e' &&
            buffer[x + 3] == 'n' &&
            buffer[x + 4] == 'n'
            ){
                fseek(textfile, cur_pos, SEEK_SET);
                fwrite(w_buffer, sizeof(char), 5, textfile);
        }
        cur_pos++;
    }


    //print out buffer
    for(int i = 0; buffer[i] != '\0'; i++){
        printf("%c", buffer[i]);
    }
    printf("\n");


    fclose(textfile);
    printf("\n");
    return 0;
}