#include <stdio.h>
#include <cs50.h>
//https://www.youtube.com/embed/QOD2hHiHpn0?autoplay=1&rel=0

/*
    Database for storing students and dorms
    they belong to into a ".cfg" file using
    STRUCTS and FILE
*/

typedef struct{
    char *sName;
    char *sDorm;
} students;

int main(){

    //open a file pointer to dump info to a .cfg file
    FILE *dataDumps = fopen("students.cfg", "w");

    //prompt usr for number of students to add
    printf("Number of students: ");
    int numStudents = get_int();

    //create an array of testbatch students
    students testbatch[numStudents];

    //prompt usr for student name and dorm
    for(int i = 0; i < numStudents; i++){
        printf("Student %i name: ", i +1);
        testbatch[i].sName = get_string();
        printf("Student %i dorm: ", i +1);
        testbatch[i].sDorm = get_string();
        printf("\n");
    }








    printf("\n");
    return 0;
}