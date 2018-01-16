#include <stdio.h>
#include <string.h>

 /*
    Bubble sort: https://edx-video.net/HARCS50X2016-V034300_DTH.mp4
    In bubble sort, the idea is to move higher valued elements at the end of the list
    and the lower valued elements at the begining of the list (ordered from least to greatest)

    Psuedo code:
        - Set a swap counter to a non zero value
        - Repeate until the swap counter is zero
            - Reset the swap counter to zero
            - Look at each djacent pair of elements
                - if two adjacent elements are not in order, swap them and add 1 to the swap counter

 */

//prototypes
void swap(int*, int*);


/* MAIN ROUTINES */

#define MAX_ELEMENTS 8
int usrArr[MAX_ELEMENTS] = {110,52,13,0,6,1,-1,200};

int main(){


    printf("Original state: ");
    for(int i = 0; i < MAX_ELEMENTS; i++){
        printf("%i ", usrArr[i]);
    }
    printf("\n");   //newline




    /* SWAP HERE */
    int swapCounter = 1;
    while(swapCounter == 1){

        swapCounter = 0;
        for(int i = 0; i < MAX_ELEMENTS - 1; i++){
            if(usrArr[i + 0] > usrArr[i + 1]){
                swap(&usrArr[i + 0], &usrArr[i + 1]);
                swapCounter = 1;
            }
        }
    }



    printf("Altered state:  ");
    for(int i = 0; i < MAX_ELEMENTS; i++){
        printf("%i ", usrArr[i]);
    }
    printf("\n");   //newline


    printf("\n");
    return 0;
}



/* SUBROUTINES */

//swap subroutine
void swap(int *param1, int *param2){    int buffer = 0;
    buffer = *param1;
    *param1 = *param2;
    *param2 = buffer;
}