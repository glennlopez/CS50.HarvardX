#include <stdio.h>
#include <cs50.h>
#include <string.h>

//OBJECT DATA-TYPE
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

    //create struct objects
    object box;
    initiate_object(&box);

    object wall;
    initiate_object(&wall);

    object npc;
    initiate_object(&npc);


    //log struct object data
    FILE *objectData;                       //create a file pointer
    objectData = fopen("log.txt", "w");     //objectData points to a writeable log.txt
    objectData = fopen("log.txt", "w");     //objectData points to a writeable log.txt

    //printf to file pointer
    fprintf(objectData, "ObjectID (wall): %i\n", wall.objectID);
    fprintf(objectData, "ObjectID (npc): %i\n", npc.objectID);
    fprintf(objectData, "ObjectID (box): %i\n", box.objectID);

    //debug - output
    printf("objectID (wall): %i\n", wall.objectID);
    printf("objectID (npc): %i\n", npc.objectID);
    printf("objectID (box): %i\n", box.objectID);

    printf("\n");   //newline
    return 0;
}




//SUBROUTINES
void initiate_object(object *(param) ){
    idCounter++;                //increments global ID counter when function is called
    param->objectID = idCounter;    //sets the object ID using the ID counter
    param->objectName = "???";
    param->objectType = 'f';
}

