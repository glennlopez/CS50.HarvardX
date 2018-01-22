#include <stdio.h>
#include <string.h>
#define MAX_ELEMENTS 15
void print_array(int []);


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

//insertion sort prototypes
void insertion_sort(int []);
void swap(int*, int*);



/* MAIN ROUTINES */
int main(){

    //unsorted list
    int usrArr[MAX_ELEMENTS] = {    //Note: Adjust MAX_ELEMENTS to scale
        200,100,-7,-3,2,66,4,1,0,99,-8,0,5, -3000, -2309
    };



    /* TEST HERE */
    printf("Random: ");
    print_array(usrArr);



    insertion_sort(usrArr);




    printf("Sorted: ");
    print_array(usrArr);


    printf("\n");
    return 0;
}




/* SUBROUTINES */

//insertion sort subroutine
void insertion_sort(int paramArr[]){
    int sdx = 0;            //sorted index
    int tdx = sdx + 1;      //target index (number that is currently being sorted)

    //loop through the entire array only once
    for(int i = 0; i < MAX_ELEMENTS; i++){

        /* 
            loop a swap function moving the target number to the left, until 
            the target number is the smaller number compared to the left-adjacent
            element, making sure tdx does not index beyond the size of the array
        */
        while( (paramArr[tdx] < paramArr[tdx - 1]) && (tdx > 0) && (tdx < MAX_ELEMENTS) ){
            swap(&paramArr[tdx], &paramArr[tdx - 1]);
            tdx--;  //keeps track of where tdx is when a swap function is called
        }

        sdx++;          //increment sorted index once an element has been sorted
        tdx = sdx + 1;  //set a new target index based on sorted index value

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