#include <stdio.h>
#include <cs50.h>
#define MAX_ELEMENTS 5

int main(){

    int source[MAX_ELEMENTS] = {5,3,2,1,8};
    int arr[MAX_ELEMENTS][MAX_ELEMENTS + 1] = {
        {0,0,0,0,0,0},
        {0,0,0,0,0,0},
        {0,0,0,0,0,0},
        {0,0,0,0,0,0},
        {0,0,0,0,0,0}
    };


    /* TEST */

    //prime sorting array with source array numbers
    for(int i = 0; i < MAX_ELEMENTS; i++){
        arr[i][0] = source[i];
    }

    //sort logic test
    if(arr[0][0] > arr[1][0]){
        arr[1][1] = arr[0][0];
    }

    /* END */


    printf("Source: ");
    for(int i = 0; i < MAX_ELEMENTS; i++){
        printf("%i ", source[i]);
    }
    printf("\n");

    printf("arr[0][0]: %i\n", arr[0][0]);
    printf("arr[1][0]: %i\n", arr[1][0]);
    printf("arr[2][0]: %i\n", arr[2][0]);
    printf("arr[3][0]: %i\n", arr[3][0]);
    printf("arr[4][0]: %i\n", arr[4][0]);

    printf("\n");
    printf("\n");


    //loop this later
    printf("%i", arr[0][0]); printf(" %i ", arr[0][1]); printf(" %i ", arr[0][2]); printf(" %i ", arr[0][3]);printf(" %i \n", arr[0][4]);

    printf("%i", arr[1][0]); printf(" %i ", arr[1][1]); printf(" %i ", arr[1][2]); printf(" %i ", arr[1][3]);printf(" %i \n", arr[1][4]);

    printf("%i", arr[2][0]); printf(" %i ", arr[2][1]); printf(" %i ", arr[2][2]); printf(" %i ", arr[2][3]);printf(" %i \n", arr[2][4]);

    printf("%i", arr[3][0]); printf(" %i ", arr[3][1]); printf(" %i ", arr[3][2]); printf(" %i ", arr[3][3]);printf(" %i \n", arr[3][4]);

    printf("%i", arr[4][0]); printf(" %i ", arr[4][1]); printf(" %i ", arr[4][2]); printf(" %i ", arr[4][3]);printf(" %i \n", arr[4][4]);

    printf("\n");
    return 0;
}