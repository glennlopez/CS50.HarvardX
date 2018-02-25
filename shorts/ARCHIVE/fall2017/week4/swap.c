#include <stdio.h>
#include <cs50.h>

void swap(int, int);

int main(){

    int a = 99;
    int b = 66;

    printf("a: %i\n", a);
    printf("b: %i\n", b);

    swap(a, b);

    printf("a: %i\n", a);
    printf("b: %i\n", b);

    printf("\n");   //new line
    return 0;
}

void swap(int param_a, int param_b){
    int temp = param_a;
    param_a = param_b;
    param_b = temp;

    printf("param_a: %i\n", param_a);
    printf("param_b: %i\n", param_b);
}