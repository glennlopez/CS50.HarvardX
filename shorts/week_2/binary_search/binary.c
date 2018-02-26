#include <stdio.h>
#include <cs50.h>

int binarySearch(int [], int);

int main(){

    //sorted array
    int ar[] = {1,2,3,4,5,6,7,8,9,10};
    int arSize = sizeof(ar)/sizeof(int);

    if(binarySearch(ar, arSize)){
        printf("Found!\n");
    }
    else{
        printf("Not found\n");
    }

    printf("\n");
    return 0;
}



/* SUBROUTINE */
int binarySearch(int param[], int paramSize){

    //initial variable sets
    int target = get_int("Search: ");
    int startPoint = 0;
    int endPoint = paramSize;
    int midPoint = paramSize;
    param[midPoint] = paramSize;

    /*
    [x] While target != midPoint do:
        [x] re-calculate midPoint -> (startPoint + endPoint)/2
        [x] if the target is in the midPoint, stop -> *number found*
        [x] if the target is lessthan midPoint, change endPoint = midPoint
        [x] if the target is greater than midPoint, change startPoint = midPoint
    */

    while(target != param[midPoint]){
        midPoint = (startPoint + endPoint)/2;
        if(target == param[midPoint]){
            return 1;
        }
        else if(startPoint == midPoint){
            return 0;
            break;
        }
        else if(target < param[midPoint]){
            endPoint = midPoint;
        }
        else if(target > param[midPoint]){
            startPoint = midPoint;
        }
    }
    return 2;
}
