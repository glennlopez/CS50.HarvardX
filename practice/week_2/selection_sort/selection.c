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
    int usrArr[MAX_ELEMENTS] = {
        7,0,3,-5,200,8,11,-8
    };



    /* TEST HERE */
    printf("Before: ");
    print_array(usrArr);

    int sorted_index = 0;
    int smallest_num = usrArr[0];
    //int sort_counter = 0;


    //--at start: set to sort_counter to 0

    //--at start: set the lowest number to be the first element on the array

    //--at start: set the sorted_index as the first element in the array


    //iterate through the array once to find the smallest number
        //keep track of smallest number using variable smallest_num
    for(int i = sorted_index ; i < MAX_ELEMENTS; i++){
        if(smallest_num > usrArr[i]){
            smallest_num = usrArr[i];
        }
    }

    //swap the first element in the array with the smallest number found in the unsorted list
        //set the sort_counter to 1






    printf("After:  ");
    print_array(usrArr);

    printf("Smallest Num: %i", smallest_num);

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