#include <stdio.h>
#include <stdlib.h>

/* TODO:
    [x] open memory card file
    [] find begining of jpeg file
        - first 3 bytes are always the same
            0xff 0xd8 0xff
        - forth byte is always 0xE? where "?"" is 0 - F
        - images are stored contigiously in memory
    [] open a new jpeg
        - there should be 50 jpeg images
    [] write 512 bytes until new JPEG is found
    [] detect EOF
*/

/* PSEUDOCODE:

    open card file
    repeate until end of card
        read 512 bytes into a buffer
        Start of a new JPEG?
            - yes -> ...
            - no -> ...
        already found a JPEG?
            - no -> ...
            - yes -> ...
    close any remaining files
*/

int main(int argc, char *argv[])
{
    // ensure proper usage
    if (argc != 2)
    {
        fprintf(stderr, "Usage: copy infile outfile\n");
        return 1;
    }

    // remember file name
    char *rawFile = argv[1];

    // open memory card file
    FILE *inptr = fopen(rawFile, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }

    // buffer
    //TODO

    // read rawFile
    //TODO

    return 0;
}