 #include <stdio.h>
 #include <cs50.h>
 #define MAX_ELEMENTS 8

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
    int unsorted[MAX_ELEMENTS] = {
        7,1,3,5,2,8,11,9
    };

    printf("Unsorted list: ");
    for(int i = 0; i < MAX_ELEMENTS; i++){
        printf("%i ", unsorted[i]);
    }
    printf("\n");



    /* SORT THE ELEMENTS HERE */




    printf("Sorted list: ");
    for(int i = 0; i < MAX_ELEMENTS; i++){
        printf("%i ", unsorted[i]);
    }
    printf("\n");



    printf("\n");
    return 0;
 }