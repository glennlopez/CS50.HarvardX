#include <stdio.h>
#include <string.h>
#define MAX_ELEMENTS 13
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


/* MAIN ROUTINES */
int main(){

    //unsorted list
    int usrArr[MAX_ELEMENTS] = {    //Note: Adjust MAX_ELEMENTS to scale
        200,100,-7,-3,2,66,4,1,0,99,-8,0,5
    };



    /* TEST HERE */
    printf("Random: ");
    print_array(usrArr);

    //FIXME: x10/+ element bug


    int sdx = 0;            //sorted index
    int tdx = sdx + 1;      //target index (number that is currently being sorted)

    //loop through an array once
    for(int i = 0; i < MAX_ELEMENTS; i++){

        //loop until the target number is the smallest 
        while( (usrArr[tdx] < usrArr[tdx - 1]) && (tdx > 0) && (tdx < MAX_ELEMENTS)){
            swap(&usrArr[tdx], &usrArr[tdx - 1]);
            tdx--;
            //print_array(usrArr);    //debug printout
        }

        sdx++;          //increment sorted index
        tdx = sdx + 1;  //set a new target index

    }






    printf("Sorted: ");
    print_array(usrArr);


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

//array print-out subroutine
void print_array(int paramArr[]){
    for(int i = 0; i < MAX_ELEMENTS; i++){
        printf("%i ", paramArr[i]);
    }
    printf("\n");   //newline
}