#include <stdio.h>
#include <stdlib.h>

int main(){
    
    //int x = 1;
    //int y = 2;
    int *x; 
    x = malloc(sizeof(int));
    
    *x = 42;
    
    int *y;
    y = malloc(sizeof(int));
    *y = 13;
    
    *x = *y;
    
    
    printf("x: %i\n",*x);
    printf("y: %i\n",*y);
    
    return 0;
}