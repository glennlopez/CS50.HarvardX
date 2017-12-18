#include <stdio.h>
#include <cs50.h>

int power(int n);


//GLOBAL VAR
int count = 0;  //<-- Placed in global so the subroutine can decrement count outside of recursion
/*
    When ever a function is called, a new stack is generated for this function.
    In recursion, a new stack will be generated until the base-case is met.

    If "count" is placed inside the recursive function instead of global, the recursive function
    will never get a chance to decrement the count value becuase a new stack is generated every time the recursive
    function is called.

    You will get a segmentation fault due to a stack overflow becuase the base-case for the recursive function is never
    met, looping function call after function call until the system runs out of memory.

*/


//MAIN FUNCTION
int main(){

    //get number from user
    printf("Number powered by itself (n^n): ");
    int uNum = get_int();

    count = uNum;
    printf( "%i to the power of %i: %i", uNum, uNum, power(uNum) );

    printf("\n");       //newline
    return 0;
}



//POWER-OF SUBROUTINE
int power(int n){

    //base case
    if(count == 1){ //<-- NOTE: count is a global variable
        return n;
    }

    //recursive case
    else{
        count--;
        return n * power(n);
    }

}