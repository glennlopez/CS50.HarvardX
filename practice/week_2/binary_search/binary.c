#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>

void binarySearch(int [], int);

int main(){

    //sorted array
    int ar[] = {1,2,3,4,5,6,7,8,9,10};
    int arSize = sizeof(ar)/sizeof(int);

    binarySearch(ar, arSize);

    //outputs
    for(int i = 0; i < 10; i++){
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
    int midPoint = 0; //FIXME: put this in while loop

    /*
    [ ] While target != midPoint do: 
        [ ] re-calculate midPoint -> (startPoint + endPoint)/2
        [ ] if the target is in the midPoint, stop -> *number found*
        [ ] if the target is lessthan midPoint, change endPoint = midPoint
        [ ] if the target is greater than midPoint, change startPoint = midPoint
    */

    while(target != midPoint){
        //FIXME: last element in the array cant be found (num:1-10)
        //FIXME: needs a way to stop looping if number cant be found
        //FIXME: if target is "0", function stops searching

        midPoint = (startPoint + endPoint)/2;
        if(target == midPoint){
            printf("Target found! \n");
        }
        else if(target < midPoint){
            endPoint = midPoint;
        }
        else if(target > midPoint){
            startPoint = midPoint;
        }

    }



    
    //debug output
    printf("target: %i\n", target);
    printf("startPoint: %i\n", startPoint);
    printf("endPoint: %i\n", endPoint);
    printf("middlePoint: %i\n", midPoint);
}
