#include<stdio.h>
#include<cs50.h>
int collatz(int);

int main(){

   /* COLLATZ
        if n is 1, stop
        otherwise if n is even, repeate this proccess on n/2
        otherwise if n is odd, repeate this proccess on 3n + 1
   */
   
    //TODO: find the most and least collatz steps of numbers 1 - 100
    //https://en.wikipedia.org/wiki/Collatz_conjecture
    int col = 7;
    
    printf("Collatz of %i is %i\n", col, collatz(col));
    printf("\n");
    return 0;
}

//subroutine
int collatz(int n){
    //basecase
    if(n == 1){
        return 0;
    }
    
    //recursive
    else if((n % 2) == 0){
        return 1 + collatz(n/2);
    }
    
    else{
        return 1 + collatz((3*n + 1));
    }
}