#include <stdio.h>
#include <cs50.h>
#include <errno.h>   // for errno
#include <limits.h>  // for INT_MAX
#include <stdlib.h>  // for strtol

int sum(int);
int sum_usrInput(int);

int main(int argc, char *argv[]){

    //user doesnt type an argument
    if(argc == 1){
        printf( "Sum: %i\n", sum_usrInput(get_int("Number: ")) );
    }

    //user enters more than 1 argument
    else if(argc > 2){
        int argCount = (argc - 1);

        for(int i = 0; i < argCount; i++){
            //FIXME: add random numbers user add
        }

        printf("ammount of numbers: %i", argCount);

    }

    //user types 1 argument
    else{

        int unum = atoi(argv[1]);
        printf( "Sum: %i\n", sum_usrInput(unum) );

    }

    printf("\n");
    return 0;
}


//summation subroutine
int sum(int n){

    //basecase
    if(n == 1){
        return n;
    }

    //recursive
    return n + (sum(n - 1));
}

//user prompt
int sum_usrInput(int n){
    int ans = sum(n);
    return ans;
}