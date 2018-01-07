#include<stdio.h>
#include<string.h>


//int usrArr[] = {3,2,1};
//int usrArr[] = {1,2,3};
int usrArr[] = {3,1,2};


//int usrArr[] = {1,2,3,4,5,6};
//int usrArr[] = {5,2,1,3,6,4};
//int usrArr[] = {5,2,1,3,4,6};
//int usrArr[] = {6,2,5,3,4,1};
//int usrArr[] = {6,5,4,3,2,1};
//int usrArr[] = {-10,300,-4,3,0,-1};
#define ARRLEN(arr) ( sizeof(arr) / sizeof(arr[0]))

int main(){
    
    //print original array
    printf("Before: ");
     for(int i = 0, n = ARRLEN(usrArr); i < n; i++){
        printf("%i ", usrArr[i]);
    }printf("\n");
    printf(" After: ");
    
    
    
    
    
    
    
    

    //PSEUDOCODE
        //sort the left half of the array (assuming n > 1)
        //sort the right half of the array (assuming n > 1)
        //merge the two halfs togehter

    
    
    
    
    
    
    
    //print sorted array
    for(int i = 0, n = ARRLEN(usrArr); i < n; i++){
        printf("%i ", usrArr[i]);
    } printf("\n");
    

    return 0;
}