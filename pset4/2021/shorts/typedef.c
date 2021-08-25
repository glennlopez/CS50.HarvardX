#include <stdio.h>
#include <cs50.h>

// Defineing Custom Data Types:
// typedef <old name> <new name>;

struct car
{
    int year;
    char* plate;
};

typedef char* string;       // typedef a char* as a string
typedef struct car car_t;   // typedef a car struct as a car

// typedef for a person struct
typedef struct person
{
    string firstname;
    string lastname;
    car_t vehicle;
} person_t;


int main()
{
    person_t player1;
    player1.firstname = "Glenn";
    player1.lastname = "Lopez";
    player1.vehicle.year = 2004;



    printf("Player 1: %s\n", player1.firstname);
    printf("Player 1 Vehicle Year: %i\n", player1.vehicle.year);



}