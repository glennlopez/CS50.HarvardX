#include <cs50.h>
#include <stdio.h>

// prototype
void swap_normal(int, int);
void swap_pointer(int* a, int* b);


int main()
{
    int A = 10;
    int B = 77;

    printf("A was: %i\n", A);
    printf("B was: %i\n", B);
    printf("\n"); //new line
    printf("\n"); //new line

    // add swap func here
    //swap_normal(A, B);
    swap_pointer(&A, &B);

    printf("A is now: %i\n", A);
    printf("B is now: %i\n", B);
    printf("\n"); //new line
    printf("\n"); //new line


}

void swap_pointer(int *a, int *b)
{
    int temp = *a;

    printf("Before heap swap: a = %i, b = %i, temp = %i\n", *a, *b, temp);
    temp = *a;
    *a = *b;
    *b = temp;
    printf("After heap swap: a = %i, b = %i, temp = %i\n", *a, *b, temp);
    printf("\n"); //new line
    printf("\n"); //new line

}


void swap_normal(int a, int b)
{
    int temp = 0;

    printf("Before stack swap: a = %i, b = %i, temp = %i\n", a, b, temp);
    temp = a;
    a = b;
    b = temp;
    printf("After stack swap: a = %i, b = %i, temp = %i\n", a, b, temp);

    printf("\n"); //new line
    printf("\n"); //new line
}