#include <stdio.h>
#include <cs50.h>

int main(){

    //force heap overflow

    int *x;
    unsigned long long i = 0;
    x = malloc(sizeof(int));

    while(x != NULL){
        //printf("Not NULL\n");
        x = malloc(sizeof(int) + 1);
        i++;
        if(x == NULL){
            break;
        }
    }

    printf("Loops: %llu", i);

    printf("\n");
    return 0;
}