#include <stdio.h>
#include <cs50.h>

int main(){
    // get line of text
    printf("Name: ");
    char *uText = get_string();

    //print string one character per line using pointer arith
    printf("Relay: ");
    for(int i = 0; uText[i] != '\0'; i++){
        printf("%c", *(uText + i)); //<-- pointer arithmatic
    }
    printf("\n");

    return 0;
}
