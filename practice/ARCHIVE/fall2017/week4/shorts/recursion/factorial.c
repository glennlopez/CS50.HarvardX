#include <stdio.h>
#include <cs50.h>

//RECURSIVE EXAMPLE
int factorial(int n){

    //BASE case
    if(n == 1){
        return 1;
    }

    //RECURSIVE case
    else{
        //return factorial( n * (n - 1) );
        return n * factorial(n - 1);
    }

}







//main routine
int main(){

    printf("Number: ");
    int uInt = get_int();

    printf("Factorial of %i is %i", uInt, factorial(uInt));

    printf("\n");   //new line
    return 0;
}