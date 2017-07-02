#include<stdio.h>
#include<cs50.h>
int collatz(int);

int main(){

   /* COLLATZ
        if n is 1, stop
        otherwise if n is even, repeate this proccess on n/2
        otherwise if n is odd, repeate this proccess on 3n + 1
   */

    //search boundary 
    int limit_low = 100;
    int limit_high = 200;
    
    int max = 0;
    int low = 2147483647;
    int highestCol = 0;
    int lowestCol = 0;
    FILE *writeData = fopen("collatz.cvs", "w");
    
    for(int i = limit_low; i < limit_high; i++){
        //highest collatz
        if(collatz(i) > max){
            max = collatz(i);
            highestCol = i;
        }
        //lowest collatz
        if(collatz(i) < low){
            low = collatz(i);
            lowestCol = i;
        }    
    }
    
    fclose(writeData);
    
    printf("Highest collatz(n): %i\n", highestCol); 
    printf("collatz(highestCol): %i\n", collatz(highestCol));   
    printf("\n");
    
    printf("Lowest collatz(n): %i\n", lowestCol); 
    printf("collatz(lowestCol): %i\n", collatz(lowestCol)); 
    //printf("collatz(n): %i\n", collatz(5)); 
    printf("\n"); 
    
    return 0;
}



//COLLATZ SUBROUTINE
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