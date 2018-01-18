#include <stdio.h>
#include <cs50.h>
#define MAX_ELEMENTS 13

 /*
    Linear Search:
        Itterate across the array from left to right searching for a specific element
    
    Psuedo Code:
        - Repeate starting at the first element
            - if the first element is what youre looking for, stop
            - else, move to the next element in the array

 */

//prototypes for selection sort
int linear_search(int [], int);



/* MAIN ROUTINE */
int main(){
    
    //unsorted list
    int usrArr[MAX_ELEMENTS] = {    //Note: Adjust MAX_ELEMENTS to scale
        -7,0,13,-95,200,-8, 15, 23,13,-4,80, -48, 0
    };

    //user prompt
    printf("Number to search: ");
    int uNum = get_int();
    
    //search for number
    linear_search(usrArr, uNum);
    



    printf("\n");
    return 0;
}


/* SUBROUTINES */

//linear search subroutine
int linear_search(int paramArr[], int targetNum){ int steps_taken = 0;
    //FIXME: sort array first

    for(int i = 0; i < MAX_ELEMENTS; i++){
        steps_taken++;
        if(paramArr[i] == targetNum){
            printf("%i found!\n", targetNum);
            
            //debug
            printf("Steps took to find '%i': %i", targetNum, steps_taken);
            return 1;
        }
    }

    printf("%i NOT found!\n", targetNum);
    
    //debug
    printf("Steps took to find '%i': %i", targetNum, steps_taken);
    return 0;
}