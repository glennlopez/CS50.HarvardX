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
void selection_sort(int []);


/* MAIN ROUTINES */
int main(){

    //unsorted list
    int usrArr[MAX_ELEMENTS] = {    //Note: Adjust MAX_ELEMENTS to scale
        -7,0,13,-95,200,-8, 15, 23,13,-4,80, -48, 0
    };



    /* TEST HERE */
    printf("Random:  ");
    print_array(usrArr);


    selection_sort(usrArr); //<-- use this function


    printf("Sorted: ");
    print_array(usrArr);


    printf("\n");
    return 0;
}




/* SUBROUTINES */

//selection sort algorythm
void selection_sort(int paramArr[]){
    int sorted_index = 0;
    int swap_counter = 1;

    while(swap_counter == 1){
        swap_counter = 0;
        for(int i = sorted_index ; i < MAX_ELEMENTS; i++){
            if(paramArr[sorted_index] > paramArr[i]){
                swap(&paramArr[sorted_index], &paramArr[i]);
                swap_counter = 1;
            }
        }
        sorted_index++;
    }
}

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