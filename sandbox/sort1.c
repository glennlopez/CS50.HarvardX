#include<stdio.h>
#include<string.h>

//int usrArr[] = {1,2,3,4,5,6};
//int usrArr[] = {5,2,1,3,6,4};
//int usrArr[] = {5,2,1,3,4,6};
//int usrArr[] = {6,2,5,3,4,1};
int usrArr[] = {6,5,4,3,2,1};
int totalSteps = 0;

#define ARRLEN(arr) ( sizeof(arr) / sizeof(arr[0]))

int main(){
    
    //print original array
    printf("Before: ");
     for(int i = 0, n = ARRLEN(usrArr); i < n; i++){
        printf("%i ", usrArr[i]);
    }printf("\n");
    printf(" After: ");
    
    
    
    
    

    //PSEUDOCODE
        //Repeat until no unsorted elements remain
            //Search unsorted part of the data to find smallest value
            //Swap the smallest value found with the first element of the unsorted part
    
    
    
    //SELECTION SORT ALGORYTHM
    int smallestNum = 9999;
    int unsortedIndex = 0;
    for(int i = 0, n = ARRLEN(usrArr); i < n -1; i++){
        
    }
    
    
    
    
    
    //print sorted array
    for(int i = 0, n = ARRLEN(usrArr); i < n; i++){
        printf("%i ", usrArr[i]);
    }
    
    
    printf("\n-------\n");
    printf("Small num: %i\n", smallestNum);
    printf("Unsorted Count: %i\n", unsortedIndex);
    printf("Array size: %i\n", (int)ARRLEN(usrArr));
    printf("Total steps to sort: %i\n", totalSteps);
    return 0;
}