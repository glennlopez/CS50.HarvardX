#include<stdio.h>
#include<string.h>
#define ARRLEN(arr) ( sizeof(arr) / sizeof(arr[0]))

void sort(int values[], int n);

int main(){
    
    
    //int usrArr[] = {1,2,3,4,5,6};
    //int usrArr[] = {5,2,1,3,6,4};
    int usrArr[] = {5,2,1,3,4,6};
    //int usrArr[] = {6,2,5,3,4,1};
    //int usrArr[] = {6,5,4,3,2,1};
    //int usrArr[] = {-10,300,-4,3,0,-1};
    
    //array size
    int size = ARRLEN(usrArr);
    
    printf("Before: ");
    for(int i = 0; i < size; i++){
        printf("%i ", usrArr[i]);
    } printf("\n");

    //sort array
    sort(usrArr, size);
    
     
    printf(" After: ");
    for(int i = 0; i < size; i++){
        printf("%i ", usrArr[i]);
    } printf("\n");
    


    return 0;
}









//SELECTION SORT ALGORYTHM - COMPARTMENTALIZED
void sort(int values[], int n){

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
        //smallestNum = values[ARRLEN(values)-1];  
    }
    //END SELECTION SORT ALGORYTHM
    
    return;
}