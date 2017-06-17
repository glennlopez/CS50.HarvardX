/**
 * helpers.c
 * 
 * Helper functions for Problem Set 3.
 */
 
#include <cs50.h>

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    //START BINARY SEARCH ALGORYTHM
    int midPoint = 0;
    int startPoint = 0;
    int endPoint = n -1;
    
    do{
        midPoint = ((endPoint + startPoint)/2);
        if(values[midPoint] != value){
            
            if(values[midPoint] < value){
                startPoint = midPoint + 1;
            }
            
            if(values[midPoint] > value){
                endPoint = midPoint - 1;
            }
            
            if(startPoint > endPoint){
                break;
            }
        }
    } 
    while(values[midPoint] != value);
    
    //return results
    if(startPoint > endPoint){
        return false;
    }
    else{
        return true;
    }
    //END BINARY SEARCH ALGORYTHM
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    //START SELECTION SORT ALGORYTHM
    int smallestNum = values[0];
    int sortedIndex = 0;

    //Repeat until no unsorted elements remain
    while(sortedIndex < n){
        
        //Search unsorted part of the data to find smallest value
        for(int i = sortedIndex; i < n ; i++){
            //Swap the smallest value found with the first element of the unsorted part
            if(values[i] < smallestNum){
                smallestNum = values[i];
                values[i] = values[sortedIndex];
                values[sortedIndex] = smallestNum;
            }
        }
        
        sortedIndex++;              //increment sorted index
        smallestNum = 2147483647;   //set smallestNum largest possible positive int 
    }
    //END SELECTION SORT ALGORYTHM
    return;
}
