#include <stdio.h>
#include <stdlib.h>

/* TODO:
    [] open memory card file
    [] find begining of jpeg file
    [] open a new jpeg
    [] write 512 bytes until new JPEG is found
    [] detect EOF

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

    // open input file
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