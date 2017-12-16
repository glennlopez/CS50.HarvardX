#include <stdio.h>
#include <cs50.h>

//FIXME: fwrite doesnt write to the txt file Read more into how fwrite works

int main(){

    char *FIXED = "testing...";

    FILE *fp;
    char *buffer;
    size_t sz;

    fp = fopen("log_fwrite.txt", "w");
    buffer = malloc( (sizeof(char) * 50) + 1 );

    for(int i = 0; FIXED[i] != '\0'; i++){
        buffer[i] = FIXED[i];
    }

    sz = fwrite(buffer, sizeof(char), 50, fp);

    printf("\n");
    return 0;
}