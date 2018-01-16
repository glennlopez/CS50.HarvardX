#include <stdio.h>
#include <string.h>
#define MAX_ELEMENTS 8
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

 int main(){

    //unsorted list
    int unsorted[MAX_ELEMENTS] = {
        7,10,3,5,2,8,11,9
    };





    /* TEST HERE */
    printf("Before: ");
    print_array(unsorted);






    printf("After:  ");
    print_array(unsorted);

    printf("\n");
    return 0;
 }


/* SUBROUTINES */

//array print-out subroutine
void print_array(int paramArr[]){
    for(int i = 0; i < MAX_ELEMENTS; i++){
        printf("%i ", paramArr[i]);
    }
    printf("\n");   //newline
}

//swap subroutine
void swap(int *param1, int *param2){    int buffer = 0;
    buffer = *param1;
    *param1 = *param2;
    *param2 = buffer;
}