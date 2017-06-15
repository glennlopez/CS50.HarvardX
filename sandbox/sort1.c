#include<stdio.h>
#include<string.h>

//int usrArr[] = {1,2,3,4,5,6};
//int usrArr[] = {5,2,1,3,6,4};
//int usrArr[] = {5,2,1,3,4,6};
//int usrArr[] = {6,2,5,3,4,1};
//int usrArr[] = {6,5,4,3,2,1};
int usrArr[] = {-10,300,-4,3,0,-1};
#define ARRLEN(arr) ( sizeof(arr) / sizeof(arr[0]))

int main(){
    
    //print original array
    printf("Before: ");
     for(int i = 0, n = ARRLEN(usrArr); i < n; i++){
        printf("%i ", usrArr[i]);
    }printf("\n");
    printf(" After: ");
    
    
    
    
    

    //PSEUDOCODE: https://www.youtube.com/watch?v=f8hXR_Hvybo
        //Repeat until no unsorted elements remain
            //Search unsorted part of the data to find smallest value
            //Swap the smallest value found with the first element of the unsorted part
    
    
    
    //SELECTION SORT ALGORYTHM
    int smallestNum = usrArr[0];
    int sortedIndex = 0;
    int n = ARRLEN(usrArr);

    //Repeat until no unsorted elements remain
    while(sortedIndex < n){
        
        //Search unsorted part of the data to find smallest value
        for(int i = sortedIndex; i < n ; i++){
            if(usrArr[i] < smallestNum){
                smallestNum = usrArr[i];
            }
        }
        
        //Swap the smallest value found with the first element of the unsorted part
        for(int i = sortedIndex; i < n ; i++){
            if(usrArr[i] == smallestNum){
                usrArr[i] = usrArr[sortedIndex];
                usrArr[sortedIndex] = smallestNum;
            }
        }
        
        sortedIndex++;              //increment sorted index
        smallestNum = 2147483647;   //set smallestNum largest possible positive int 
    }


    
    
    
    
    
    
    //print sorted array
    for(int i = 0; i < n; i++){
        printf("%i ", usrArr[i]);
    } printf("\n");
    

    return 0;
}