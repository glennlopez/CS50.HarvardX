#include <stdio.h>
#include <cs50.h>
#include <string.h>

int objectCount = 0;
typedef struct{
    int objectID;
    char *objectName;
    char objectType;
} object;


//GLOBAL VARIABLES
object box = {
    1,
    "test",
    'c'
};

//PROTOTYPE FUNCTIONS
void initiate_object(object *(param));






//MAIN ROUTINE
int main(){

    //initiate_object(box); //<-- WILL NOT WORK
    /*
        Above does not work becuase it is passing a copy of a variable to the function
        and mannipulating it within that new stack. Passing by reference (&box) vs
        passing by variable (box) allows the function to manipulate the variable's data in memory (&box)
        rather than making a copy of it to pass to the function (box).
    */

    initiate_object(&box);

    //box.objectID = 100;
    printf("objectID: %c", box.objectType);


    printf("\n");   //newline
    return 0;
}







/* WILL NOT WORK

void initiate_object(object *(param) ){
    param->objectID = objectCount++;
    param->objectName = "???";
    param->objectType = 'x';
}
*/

void initiate_object(object *(param) ){
    param->objectID = objectCount++;
    param->objectName = "???";
    param->objectType = 'x';
}

