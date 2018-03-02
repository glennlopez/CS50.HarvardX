// Helper functions for music

#include <cs50.h>
#include <math.h>
#include "helpers.h"

// Converts a fraction formatted as X/Y to eighths
int duration(string fraction)
{
    int result = 0;

    //simple ascii-char to int conversion
    int numer = (int)fraction[0] - 48;
    int denom = (int)fraction[2] - 48;

    if (denom == 8)
    {
        result = numer;
    }
    else if (numer == 1)
    {
        result = 8 / denom;
    }

    return result;
}

// Calculates frequency (in Hz) of a note
int frequency(string note)
{
    int strCnt = 0;
    int n_exponent = 0;
    double tone_frq = 0;
    int octive = 0;
    int octive_pos = 0;
    int octive_frq = 0;
    char tone[] =
    {
        'A', '?', 'B', 'C', '?', 'D', '?', 'E', 'F', '?', 'G', '?', '\0'
    };

    //acidental offset adjustment for octive
    for (strCnt = 0; note[strCnt] != '\0'; strCnt++);
    if (strCnt == 3)
    {
        octive_pos = 2;
    }
    if (strCnt == 2)
    {
        octive_pos = 1;
    }

    //octive to frequency calculator
    octive = (int)note[octive_pos] - 48;
    if ((note[0] == 'A') || (note[0] == 'B'))
    {
        octive_frq = 440 * (pow(2, octive - 4));
    }
    //corrects for octive roll-over
    else
    {
        octive_frq = 440 * (pow(2, octive - 5));
    }

    //find n to calculate for tone: 2^(n/12)
    for (n_exponent = 0; tone[n_exponent] != note[0]; n_exponent++)
    {
        if (n_exponent > 11)
        {
            n_exponent = 0;
            break;
        }
    }

    //calculate for tone frequency
    tone_frq = octive_frq * pow(2, (n_exponent / 12.0000));

    //accidentals to frequency
    if ((strCnt == 3) && (note[1] == '#'))
    {
        tone_frq *= pow(2, (1 / 12.0000));
    }
    if ((strCnt == 3) && (note[1] == 'b'))
    {
        tone_frq /= pow(2, (1 / 12.0000));
    }

    //return a rounded frequency int
    return round(tone_frq);
}

// Determines whether a string represents a rest
bool is_rest(string s)
{
    //count the number of characters in the string
    int counter = 0;
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s[i] != '\0')
        {
            counter++;
            break;  //dont waste anymore time
        }
    }

    //determine rest from counter
    if (counter <= 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}