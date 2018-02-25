#include <stdio.h>
#include <cs50.h>
#define MAX_ELEMENTS 13
void print_array(int []);

 /*
    Linear Search:
        Itterate across the array from left to right searching for a specific element
    
    Psuedo Code:
        - Repeate starting at the first element
            - if the first element is what youre looking for, stop
            - else, move to the next element in the array

 */

//prototypes for sorting algorithms
int linear_search(int [], int);
void insertion_sort(int []);
void selection_sort(int []);
void swap(int *, int *);



/* MAIN ROUTINE */
int main(){
    
    //unsorted list
    int usrArr[MAX_ELEMENTS] = {    //Note: Adjust MAX_ELEMENTS to scale
        -7,0,13,-95,200,-8, 15, 23,13,-4,80, -48, 0
    };

    //print array for user to see for testing
    print_array(usrArr);
    printf("\n");
    printf("\n");

    //user prompt
    printf("Number to search: ");
    int uNum = get_int();
    printf("Sort the array before search [y/n]: ");
    char uChar = get_char(); 

    //sort if required
    if( (uChar == 'y') || (uChar == 'Y')){
        //selection_sort(usrArr);
        insertion_sort(usrArr);
    }
    
    //search for number specified by usr
    linear_search(usrArr, uNum);
    
    printf("\n");
    return 0;
}



/* SUBROUTINES */

//linear search subroutine
int linear_search(int paramArr[], int targetNum){ int steps_taken = 0;

    for(int i = 0; i < MAX_ELEMENTS; i++){
        steps_taken++;
        if(paramArr[i] == targetNum){
            printf("Results: %i found!\n", targetNum);
            
            //debug
            printf("Steps taken to find '%i': %i", targetNum, steps_taken);
            return 1;
        }
    }

    printf("Results: %i NOT found!\n", targetNum);
    
    //debug
    printf("Steps taken to find '%i': %i", targetNum, steps_taken);
    return 0;
}

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