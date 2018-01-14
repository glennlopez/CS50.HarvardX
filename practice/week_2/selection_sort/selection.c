#include <stdio.h>
#include <string.h>
#define MAX_ELEMENTS 8
#define ARRLEN(arr) ( sizeof(arr) / sizeof(arr[0]))

void sort(int values[], int n);

 /*
    Selection sort: https://edx-video.net/HARCS50X2016-V035200_DTH.mp4
    Find the smallest unsorted element and add it to the end of the sorted list

    Pseudo code:
        - Repeat the following steps until no no unsorted elements remain
            - search through the unsorted part of the data and find the smallest value
            - swap the smallest found value with the first element of the unsorted list
 */

 int main(){

    //unsorted list
    int unsorted[8] = {
        7,10,3,5,2,8,11,9
    };

    //calculate array size
    int size = ARRLEN(unsorted);

    printf("Unsorted list: ");
    for(int i = 0; i < size; i++){
        printf("%i ", unsorted[i]);
    }
    printf("\n");



    /* ELEMENTS ARE SORTED HERE HERE */




    printf("Sorted list:   ");
    for(int i = 0; i < size; i++){
        printf("%i ", unsorted[i]);
    }
    printf("\n");

    printf("\n");
    return 0;
 }



