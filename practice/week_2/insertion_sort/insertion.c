#include <stdio.h>
#include <string.h>
#define MAX_ELEMENTS 5
void print_array(int []);
void swap(int*, int*);


 /*
    Insertion sort: https://edx-video.net/HARCS50X2016-V032900_DTH.mp4
    Builds your sorted array in place, shifting elements out of the way if
    neccessary to make room as you go

    Psuedo code:
        - Call the first element of the array sorted
        - Repeate until all the elements in the array are sorted
           - Look at the next unsorted element
           - Insert into the sorted ortion by shifting the required number of elements


 */

//prototypes for selection sort
//FIXME: place selection sort routine prototype here


/* MAIN ROUTINES */
int main(){

    //unsorted list
    int usrArr[MAX_ELEMENTS] = {    //Note: Adjust MAX_ELEMENTS to scale
        5,3,2,1,8
    };



    /* TEST HERE */
    printf("Random: ");
    print_array(usrArr);




    //FIXME: Call the selection sort function here


    for(int i = 0; i < MAX_ELEMENTS; i++){
        if(usrArr[i + 0] > usrArr[i + 1]){
            swap(&usrArr[i + 0], &usrArr[i + 1]);
        }

    }



    printf("Sorted: ");
    print_array(usrArr);


    printf("\n");
    return 0;
}




/* SUBROUTINES */

//FIXME: create a selection sort subroutine


//swap subroutine
void swap(int *param1, int *param2){    int buffer = 0;
    buffer = *param1;
    *param1 = *param2;
    *param2 = buffer;
}

//array print-out subroutine
void print_array(int paramArr[]){
    for(int i = 0; i < MAX_ELEMENTS; i++){
        printf("%i ", paramArr[i]);
    }
    printf("\n");   //newline
}