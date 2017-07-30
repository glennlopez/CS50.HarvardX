#include <stdio.h>
#include <cs50.h>

int main(){
    
    //memory allocate int
    int *px = NULL;
    px = malloc(sizeof(int));
    if(px == NULL){
        printf("Error - Int\n");
        return 1;
    }
    
    free(px); 
    
    //memory alocate a string
    char *name = NULL;
    name = malloc(50 * sizeof(char));
    if(name == NULL){
        printf("Error - Char\n");
        return 1;
    }
    
    free(name);
    
    return 0;
}