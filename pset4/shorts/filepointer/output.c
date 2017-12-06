#include <stdio.h>
#include <cs50.h>
#include <string.h>

int objectCount = 0;
typedef struct{
    int objectID;
    char *objectName;
    char objectType;
} object;


//PROTOTYPES
void initiate_object(object *(param));


//GLOBAL VARIABLES
int idCounter = 1000;    //sets the counter base number

//MAIN ROUTINE
int main(){

    object box;
    initiate_object(&box);

    object wall;
    initiate_object(&wall);

    object npc;
    initiate_object(&wall);

    //debug - output
    printf("objectID (wall): %i\n", wall.objectID);
    printf("objectID (box): %i\n", npc.objectID);
    printf("objectID (box): %i\n", box.objectID);

    printf("\n");   //newline
    return 0;
}




//SUBROUTINES
void initiate_object(object *(param) ){
    idCounter++;                    //increments global ID counter when function is called
    param->objectID = idCounter;    //sets the object ID using the ID counter
    param->objectName = "???";
    param->objectType = 'f';
}

