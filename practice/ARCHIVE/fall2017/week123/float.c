#include<cs50.h>
#include<stdio.h>

int main(){
    
    printf("Number 1: ");
    float i = get_float();
    printf("Number 2: ");
    float j = get_float();
    //int total = i + j;

    //printf("Total: %i", total);
    //printf("Total: %i", i+j);
    printf("Add: %f\n", i + j);
    printf("Subtract: %f\n", i - j);
    printf("Multiply: %f\n", i * j);
    printf("Division: %f\n", i / j);
    //printf("Remainder: %f\n", i % j);
    
    printf("\n"); //newline
    return 0;
}