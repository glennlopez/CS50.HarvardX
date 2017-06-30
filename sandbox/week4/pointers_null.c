#include<stdio.h>
#include<cs50.h>

int main(){
    
    int k;
    k = 5;
    
    //int *pk = NULL; //* means "memory address of"
    
    
    //pk = &k; //& means "address of"
    //pk = malloc(sizeof(int));
    int *pk = malloc(sizeof(int));
    
    *pk = 10;
    
    if(pk == NULL){
        printf("Pointer is NULL\n");
    }
    else{
        printf("Pointer is not NULL\n");
    }
    
    printf("k: %i pk: %i\n", k, *pk);
    
    printf("\n");
    return 0;
}