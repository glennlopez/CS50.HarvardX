#include <stdio.h>
#include <cs50.h>

int main(){
    int *x = NULL;
    int *y = NULL;

    x = malloc(sizeof(int) * 1);
    y = malloc(sizeof(int) * 1);

    *x = 42;
    //*y = (int)&x;
    *y = *x;

    printf("%p: %d", &x,*x);
    printf("\n");
    printf("%p: %d", &y,*y);

    free(x);
    free(y);


    printf("\n");
    return 0;
}
