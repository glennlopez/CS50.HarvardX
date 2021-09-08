// dynamic memory is allocated when we dont know how much memory a program needs during runtime

#include<cs50.h>
#include<stdio.h>
#include<stdlib.h>


int main()
{

    // ask the user how many numbers to store in heap
    int iCount = get_int("How many numbers to store: ");

    // create dynamic memory allocation for the variable
    int *num = malloc(iCount * sizeof(int));

    // ask user what numbers to store in those heap storage
    for (int i = 0; i < iCount; i++)
    {
        // store those numbers in heap for the user
        *(num + i) = get_int("Number %i: ", i + 1);
    }



    // print out the numbers stored in heap
    for (int i = 0 ; i < iCount; i++)
    {
        printf("%i ", *(num + i));
    }
    printf("\n");

    free(num);

}