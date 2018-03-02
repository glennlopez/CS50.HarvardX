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

    int strCnt = 0;
    int n_exponent = 0;
    double tone_frq = 0;
    int octive = 0; int octive_pos = 0; int octive_frq = 0;
    char tone[] = {
        'A','?','B','C','?','D','?','E','F','?','G','?','\0'
    };

    //acidental offset adjustment for octive
    for(strCnt = 0; note[strCnt] != '\0'; strCnt++);
    if(strCnt == 3){
        octive_pos = 2;
    }
    if(strCnt == 2){
        octive_pos = 1;
    }

    //octive to frequency calculator
    octive = (int)note[octive_pos] - 48; 
    if( (note[0] == 'A') || (note[0] == 'B') ){ 
        octive_frq = 440 * ( pow(2,octive - 4) );
    }
    else{ //corrects for octive roll-over
        octive_frq = 440 * ( pow(2,octive - 5) );
    }

    //find n to calculate for tone: 2^(n/12)
    for(n_exponent = 0; tone[n_exponent] != note[0]; n_exponent++){
        if(n_exponent > 11){    //prevents non-sensical notes
            n_exponent = 0;
            break;
        }
    }

    //calculate for tone frequency
    tone_frq =  octive_frq * pow(2, (n_exponent/12.0000));

    //accidentals to frequency
    if( (strCnt == 3) && (note[1] == '#') ){
        tone_frq *= pow(2, (1/12.0000));
    }
    if( (strCnt == 3) && (note[1] == 'b') ){
        tone_frq /= pow(2, (1/12.0000));
    }

    //return a rounded frequency int 
    return round(tone_frq);
}