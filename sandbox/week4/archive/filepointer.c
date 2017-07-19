#include<stdio.h>
#include<cs50.h>
long long collatz(long long);

int main(){

   /* COLLATZ CONJECTURE
        if n is 1, stop
        otherwise if n is even, repeate this proccess on n/2
        otherwise if n is odd, repeate this proccess on 3n + 1
   */

    //search boundary 
    long long limit_low = 1;
    long long limit_high = 1000000;
    
    long long max = 0;
    long long low = 2147483647;
    long long highestCol = 0;
    long long lowestCol = 0;
    
    //open file pointer to write data
    FILE *writeData = fopen("collatz.csv", "w");
    if(writeData == NULL){
        printf("Null Pointer Error!\n");
        return 1;
    }
    
    for(long long i = limit_low; i <= limit_high; i++){
        //collect datadump - save to cvs for graphing
        fprintf(writeData, "%lli,%lli\n", i, collatz(i));
        
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
    
    //close file in file pointer
    fclose(writeData);
    
    
    //DEBUG PRINT
    printf("Highest collatz(n): %lli\n", highestCol); 
    printf("collatz(highestCol): %lli\n", collatz(highestCol));   
    printf("\n");
    
    printf("Lowest collatz(n): %lli\n", lowestCol); 
    printf("collatz(lowestCol): %lli\n", collatz(lowestCol)); 
    //printf("collatz(n): %i\n", collatz(5)); 
    printf("\n"); 
    
    return 0;
}



//COLLATZ SUBROUTINE
long long collatz(long long n){
    //basecase
    if(n == 1)  //<-- if n is 1, stop
        return 0;
    
    //recursive
    else if((n % 2) == 0)
        // otherwise if n is even, repeate this proccess on n/2
        return 1 + collatz(n/2); 
    else
         // otherwise if n is odd, repeate this proccess on 3n + 1
        return 1 + collatz((3*n + 1));
}