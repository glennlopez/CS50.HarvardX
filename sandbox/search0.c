#include<stdio.h>
#include<string.h>


//int usrArr[] = {1,2,3,4,5,6,7,8};
//int usrArr[] = {4,9,13,24,56,66,67,80};
//int usrArr[] = {5,2,1,3,6,4};
//int usrArr[] = {5,2,1,3,4,6};
//int usrArr[] = {6,2,5,3,4,1};
//int usrArr[] = {6,5,4,3,2,1};
//int usrArr[] = {-10,300,-4,3,0,-1};
int usrArr[] = {-10,-4,3,0,33,68,200,3000};
#define ARRLEN(arr) ( sizeof(arr) / sizeof(arr[0]))

int main(){
    
    /*
    //print original array
    printf("Before: ");
     for(int i = 0, n = ARRLEN(usrArr); i < n; i++){
        printf("%i ", usrArr[i]);
    }printf("\n");
    printf(" After: ");
    */
    
    
    
    
    
    
    
    
    
    
    

    
    
    //BINARY SEARCH ALGORYTHM
    int target = -2;
    int midPoint = 0;
    int startPoint = 0;
    int endPoint = (ARRLEN(usrArr) -1);
    
    do{
        midPoint = ((endPoint + startPoint)/2);
        if(usrArr[midPoint] != target){
            
            if(usrArr[midPoint] < target){
                startPoint = midPoint + 1;
            }
            
            if(usrArr[midPoint] > target){
                endPoint = midPoint - 1;
            }
            
            if(startPoint > endPoint){
                break;
            }
        }
    } while(usrArr[midPoint] != target);
    
    //call outs
    if(startPoint > endPoint){
        printf("%i NOT found.\n", target);
    }
    if(usrArr[midPoint] == target){
        printf("%i is FOUND.\n", target);
    }
    //END BINARY SEARCH ALGORYTHM
    
    
    
    
    
    
    
    
    
    
    /*
    //print sorted array
    for(int i = 0, n = ARRLEN(usrArr); i < n; i++){
        printf("%i ", usrArr[i]);
    } printf("\n");
    
     printf("----------------\n");
     */
    
    printf("MidPoint: usrArr[%i]\n", midPoint);
    printf("StartPoint: usrArr[%i]\n", startPoint);
    printf("EndPoint: usrArr[%i]\n", endPoint);
    

    return 0;
}