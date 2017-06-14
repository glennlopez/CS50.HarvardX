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
    for(int i = 0; i < ARRLEN(usrArr); i++){
        printf("%i ", usrArr[i]);
    }printf("\n");
    printf(" After: ");
    
    
    
    
    
    //PSEUDOCODE
        //set swap counter to a non-zero value
        //Repeat untill the swap counter is 0
            //Reset swap counter to 0
            //Look at each adjacent pair in the array
                //If the two adj pair are not ordered: 
                    //swap them 
                    //increment the swapcounter
    
    
    //BUBBLE SORT ALGORYTHM
    int swapCounter = -1;
    int buffer = -9999;
    
    do{
        swapCounter = 0;
        
        for(int i = 0, n = ARRLEN(usrArr); i < n -1; i++){
        
            if(usrArr[i] > usrArr[i+1]){
                buffer = usrArr[i+1];       totalSteps++;
                usrArr[i+1] = usrArr[i];    totalSteps++;
                usrArr[i] = buffer;         totalSteps++;
                swapCounter++;
            }
                                            totalSteps++;   //min arraylen(arr) steps
        } 
        
    }while(swapCounter != 0);
    //END BUBBLE SORT ALGORYTHM
    
    
    
    
    
    //print sorted array
    for(int i = 0; i < ARRLEN(usrArr); i++){
        printf("%i ", usrArr[i]);
    }
    
    printf("\n-------\n");
    printf("Array size: %i\n", (int)ARRLEN(usrArr));
    printf("Total steps to sort: %i\n", totalSteps);
    return 0;
}