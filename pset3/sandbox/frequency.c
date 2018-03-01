#include<stdio.h>
#include<cs50.h>
#include<math.h>
int frequency(string note);

int main(void){
    string s = get_string("String: ");

    printf("frequency: %i", frequency(s));

    printf("\n");
    return 0; 
} 





/* SUBROUTINES */
// Calculates frequency (in Hz) of a note
int frequency(string note){
    //int frq = 0; 
    int strCnt = 0;
    int n_exponent = 0;
    int octive = 0;
    int octive_frq = 0;
    double note_frq = 0;
    char tone[] = {
        'A','?','B','C','?','D','?','E','F','?','G','?','\0'
    };

    //octive to frequency:
    octive = (int)note[1] - 48; //calculates octives from 1 to 9

    if( (note[0] == 'A') || (note[0] == 'B') ){ 
        octive_frq = 440 * ( pow(2,octive - 4) );
    }
    else{ //corrects for octive roll-over
        octive_frq = 440 * ( pow(2,octive - 5) );
    }
    //FIXME: G4 should be 392, G3 shows up as 392
    /*
        C4 - (261.63)   524
        D4 - (293.66)   588
        E4 - (329.63)   660
        F4 - (349.23)   699
        G4 - (392.00)   784
        A4 - works      (440.00)
        B4 - works      (493.88)
        C5 - (523.25)   1047
    */

    //count the number of char in the string   
    for(strCnt = 0; note[strCnt] != '\0'; strCnt++);
        //if 3 then octive is at note[2]
        //if 2 then octive is at note[1]

    //find exponent(n) for tone calculation 2^(n/12)
    for(n_exponent = 0; tone[n_exponent] != note[0]; n_exponent++){
        if(n_exponent > 11){    //prevents non-sensical notes
            n_exponent = 0;
            break;
        }
    }

    //accidentals to frequency
        //sharp (#)
        //flats (b)

    //Return frq:
        // [2 ^ (octive - 4) * (Note Frequency)] +/- accidental frequency = frq
        note_frq =  octive_frq * pow(2, (n_exponent/12.00000));

    //return rounded number
    return ceil(note_frq);
}