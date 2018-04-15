#include <stdio.h>
#include <stdlib.h>

int main(){

    // file pointer for reading textfile
    FILE *inptr = fopen("fakebmp.txt", "r");
    if(inptr == NULL){
        fprintf(stderr, "Error 1002: Could not open file!\n");
        return 1002;
    }

    // file pointer for writing textfile
    FILE *outptr = fopen("out_fakebmp.txt", "w");
    if(outptr == NULL){
        fprintf(stderr, "Error 1003: Could not write to file!\n");
        return 1003;
    }

    // read the text into a buffer
    // fread(<buffer>, <size>, <qty>, <file pointer>);
    char *triple = malloc(sizeof(char) * 3);
    fread(triple, sizeof(char), 3, inptr);
    fwrite(triple, sizeof(char), 3, outptr);

    // TODO: OUTPUT TO ANOTHER FILE

    // debug print
    /*
    for(int i = 0; i < 6; i++){
        printf("%c", triple[i]);
    }
    printf("\n");
    */

    // free malloc mem
    free(triple);

    // close read-only file pointer
    fclose(inptr);

    printf("\n");
    return 0;
}