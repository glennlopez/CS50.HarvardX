#include <stdio.h>
#include <string.h>
#define MAX_ELEMENTS 13
void print_array(int []);
void swap(int*, int*);


 /*
    Selection sort:
    https://edx-video.net/HARCS50X2016-V035200_DTH.mp4
    https://www.youtube.com/watch?v=g-PGLbMth_g&spfreload=10
    Find the smallest unsorted element and add it to the end of the sorted list

    Pseudo code:
        - Repeat the following steps until no no unsorted elements remain
            - search through the unsorted part of the data and find the smallest value
            - swap the smallest found value with the first element of the unsorted list
 */

//prototypes for selection sort
//FIXME: place selection sort routine prototype here


/* MAIN ROUTINES */
int main(){

    //unsorted list
    int usrArr[MAX_ELEMENTS] = {    //Note: Adjust MAX_ELEMENTS to scale
        -7,0,13,-95,200,-8, 15, 23,13,-4,80, -48, 0
    };



    /* TEST HERE */
    printf("Random:  ");
    print_array(usrArr);




    //FIXME: Call the selection sort function here



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