#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#define ARRLEN(arr) ( sizeof(arr) / sizeof(arr[0]))

//prototype
bool search(int value, int values[], int n);

int main(){
    
    int usrArr[] = {1,2,3,4,5,6,7,8};
    //int usrArr[] = {4,9,13,24,56,66,67,80};
    //int usrArr[] = {5,2,1,3,6,4};
    //int usrArr[] = {5,2,1,3,4,6};
    //int usrArr[] = {6,2,5,3,4,1};
    //int usrArr[] = {6,5,4,3,2,1};
    //int usrArr[] = {-10,300,-4,3,0,-1};
    //int usrArr[] = {-10,-4,3,0,33,68,200,3000};
    
    //array size
    int size = ARRLEN(usrArr);
    //number to look for
    int needle = 21;
    
    // try to find needle in haystack
    if (search(needle, usrArr, size)){
        printf("\nFound needle in haystack!\n\n");
        return 0;
    }
    else{
        printf("\nDidn't find needle in haystack.\n\n");
        return 1;
    }
    
    return 0;
}






//BINARY SEARCH - COMPARTMENTALIZED
bool search(int value, int values[], int n){
    
    //BINARY SEARCH ALGORYTHM
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



