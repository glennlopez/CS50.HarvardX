#include<stdio.h>
#include<cs50.h>

int main(){
    
    int k;
    k = 5;
    
    int *pk; //* means "memory address of"
    pk = &k; //& means "address of"
    
    printf("k: %i pk: %i\n", k, *pk);
    
    printf("\n");
    return 0;
}