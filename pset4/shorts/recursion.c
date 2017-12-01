#include <stdio.h>
#include <cs50.h>

int factorial(int num){

    //default case


    return 0;
}

int main(){

    printf("Number: ");
    int uInt = get_int();

    printf("Factorial of %i is %i", uInt, factorial(uInt));

    printf("\n");   //new line
    return 0;
}