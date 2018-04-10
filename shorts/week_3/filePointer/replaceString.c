#include <stdio.h>
#include <cs50.h>

#define MAX_CHAR 500    //maximum char to scan into buffer

int main(){

    // user prompt
    string seekString = get_string("Replace: ");
    string uString = get_string("With: ");

    // count uString Length
    int uStringLength = 0;
    for(int i = 0; uString[i] != '\0'; i++){
        uStringLength++;
    }

    // count uString Length
    int seekStringLen = 0;
    for(int i = 0; seekString[i] != '\0'; i++){
        seekStringLen++;
    }

    // set a file pointer to read sample.txt
    FILE *textfile;
    textfile = fopen("sample.txt", "r+");
    if(textfile == NULL){
        return 1;
    }

    //read data and store to buffer
    char *buffer = malloc(sizeof(char) * MAX_CHAR);
    fread(buffer, sizeof(char), MAX_CHAR, textfile);

    //replacement routine
    int cur_pos = 0;
    for(int i = 0; buffer[i] != '\0'; i++){
        int compareCnt = 0;
        for(int j = 0; j < seekStringLen; j++){
            if(buffer[i + j] == seekString[j]){
                compareCnt++;
            }
            if(compareCnt == seekStringLen){
                fseek(textfile, cur_pos, SEEK_SET);
                fwrite(uString, sizeof(char), uStringLength, textfile);
            }
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