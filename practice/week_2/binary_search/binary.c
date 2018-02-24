#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>

void binarySearch(int [], int);

int main(){

    //sorted array
    int ar[] = {1,2,3,4,5,6,7,8,9,10,11,12};
    int arSize = sizeof(ar)/sizeof(int);

    binarySearch(ar, arSize);

    //outputs
    for(int i = 0; i < arSize; i++){
        printf("%i ", *(ar + i));
    }

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
        else if(target < param[midPoint]){
            endPoint = midPoint;
        }
        else if(target > param[midPoint]){
            startPoint = midPoint;
        }

        //number doesnt exist, stop looping
        if( (endPoint - startPoint) == 1){
            printf("Target NOT found!\n");
            break;
        }


    }



    
    //debug output
    printf("target: %i\n", target);
    printf("startPoint: %i\n", startPoint);
    printf("endPoint: %i\n", endPoint);
    printf("middlePoint: %i\n", midPoint);
}
