// Helper functions for music

#include <cs50.h>

#include "helpers.h"

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

// Calculates frequency (in Hz) of a note
int frequency(string note)
{
    // TODO
}

// Determines whether a string represents a rest
bool is_rest(string s){
    
    //count the number of characters in the string
    int counter = 0;
    for(int i = 0; s[i] != '\0'; i++){
        if(s[i] != '\0'){
            counter++;
            break;  //dont waste anymore time
        }
    }

    //determine rest from counter
    if(counter <= 0){
        return 1;
    }
    else{
        return 0;
    }
}