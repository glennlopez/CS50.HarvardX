#include <stdio.h>
#include <cs50.h>

int main(){
    //string test = "testing 123 hi @#$%";
    char *test = "pointer testing 123 hi @#$%";

    for(int i = 0; test[i] != '\0'; i++){
        printf("%c",  *(test + i));
    }
    printf("\n");



    printf("\n");
    return 0;
}