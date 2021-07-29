#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // todo: prompt user for name
    string uname = get_string("What is your name: ");

    // todo: say hello to user
    printf("Hello %s \n", uname);
}