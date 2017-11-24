#include<stdio.h>
#include<cs50.h>
long long factorial(long long);

int main(){

   /* FACTORIAL
        5! = 5 * 3 * 2 * 1 = 120
   */
   
    int unum = 5;
   
    printf("Factorial of %i is %lli", unum, factorial(unum));
    
    
    printf("\n");
    return 0;
}

//factorial subroutine
long long factorial(long long param){
    //basecase
    if(param == 1)
        return param;
    
    //recursive routine
    else
        return param * factorial(param - 1);
}