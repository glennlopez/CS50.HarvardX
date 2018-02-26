#include <stdio.h>
#include <cs50.h>
int getFactorial(int);

int main(){

    int num = get_int("Factorial: ");

    printf("Result: %i", getFactorial(num));
    printf("\n");
    return 0;
}

/* SUBROUTINE */
int getFactorial(int n){
    //base case
    if(n == 1){
        return n;
    }

    //recursive case
    else{
        return getFactorial(n - 1) * n;
    }
}