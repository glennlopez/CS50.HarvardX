/*
    [] Use fread to read the contents of a file
    [] Use heap memory to store the buffer
*/

#include <stdio.h>
#include <cs50.h>

int main(){

    FILE *fp;
    char *buffer = malloc( (sizeof(char) * 50) + 1 );
    size_t sz;

    fp = fopen("log_fread.txt", "r");
    sz = fread(buffer, sizeof(char), 50, fp);

    //print to screen
    printf("%s", buffer);

    //cleanup routine
    fclose(fp);
    free(buffer);

    printf("\n");
    return 0;
}