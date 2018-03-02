#include<stdio.h>
#include<cs50.h>
int duration(string fraction);

int main(void){
    string s = get_string("String: ");

    printf("duration: %i", duration(s));

    printf("\n");
    return 0; 
} 





/* SUBROUTINES */
// Converts a fraction formatted as X/Y to eighths
int duration(string fraction){
    int result = 0;

    //simple ascii-char to int conversion
    int numer = (int)fraction[0] - 48;
    int denom = (int)fraction[2] - 48; 

    if(denom == 8){
        result = numer;
    }
    else if(numer == 1){
        result = 8/denom;
    }

    return result;
}