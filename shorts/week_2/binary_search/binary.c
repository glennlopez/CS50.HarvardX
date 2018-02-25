#include <stdio.h>
#include <cs50.h>

void binarySearch(int [], int);

int main(){

    //sorted array
    int ar[] = {-10,-6,-1,0,1,23,55,1002};
    int arSize = sizeof(ar)/sizeof(int);

    binarySearch(ar, arSize);

    printf("\n");
    return 0;
}




/* SUBROUTINE */
void binarySearch(int param[], int paramSize){

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
            printf("Target found! \n");
        }
        else if(startPoint == midPoint){
            printf("Target NOT found!\n");
            break;
        }
        else if(target < param[midPoint]){
            endPoint = midPoint;
        }
        else if(target > param[midPoint]){
            startPoint = midPoint;
        }
    }
}
