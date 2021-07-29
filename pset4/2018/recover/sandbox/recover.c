#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


/* TODO:
    [x] open memory card file
    [] find begining of jpeg file
        - first 3 bytes are always the same
            0xff 0xd8 0xff
        - forth byte is always 0xE? where "? is 0 - F
        - images are stored contigiously in memory
    [] open a new jpeg
        - there should be 50 jpeg images
    [] write 512 bytes until new JPEG is found
    [] detect EOF
*/

/* PSEUDOCODE:

    1. open card file
    2. repeate until end of card
        3. read 512 bytes into a buffer
        4. Start of a new JPEG?
            - yes -> ...
            - no -> ...
        5. already found a JPEG?
            - no -> ...
            - yes -> ...
    close any remaining files
*/



int main(int argc, char *argv[])
{
    // ensure proper command line usage
    if (argc != 2)
    {
        fprintf(stderr, "Usage: copy infile outfile\n");
        return 1;
    }

    // remember file name
    char *rawFile = argv[1];

    // 1. open memory card file
    FILE *inptr = fopen(rawFile, "r");
    FILE *inptr_EOF = fopen(rawFile, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", rawFile);
        return 2;
    }


    // open output file
    FILE *outptr = fopen("outfile.jpeg", "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create outfile.jpeg.\n");
        return 3;
    }







    // infile buffer
    uint8_t buffer[512 + 3];

    // 2. repeate until end of card
    int dataByte;
    int dataIndex = 0;
    int jpgFound = 0;
    int jpgEnd = 0;
    int jpgCount = 0;   //debug
    while( (dataByte = fgetc(inptr_EOF)) != EOF )
    {
        // 3. read 512 bytes into a buffer
        for(int i = 0; i < 512; i++)
        {
            fread(&buffer[i], sizeof(uint8_t), 1, inptr);
        }

        for(int i = 0; i < 512; i++)
        {

            // 4. Start of a new JPEG?
            if( (buffer[i] == 0xFF) && (buffer[i+1] == 0xD8) && (buffer[i+2] == 0xFF) && jpgFound == 0)
            {
                printf("\n\n\n\n\n\n\n ------------ NEW JPEG ------------ \n\n\n\n\n\n\n"); //debug
                jpgEnd = 0;
                jpgFound = 1;
                jpgCount++; //debug
            }

            if(jpgFound == 1)
            {
                // write data[i] to outfile
                printf("%X ", buffer[i]); //debug
                fwrite(&buffer[i], sizeof(uint8_t), 1, outptr);
            }

            // end block loop if end of jpeg is found
            /*
            if( (buffer[i] == 0xFF) && (buffer[i+1] == 0xD9) )
            {
                jpgFound = 0;
                jpgEnd = 1;
                break;
            }
            */
        }

        // fgetc EOF seek_set
        fseek(inptr_EOF,dataIndex, SEEK_SET);
        dataIndex += 512;
    }


    /*
    for(int i = 0; i < 512; i++)
    {
        printf("%X ", buffer[i]);
    }
    */
    printf("\n");




    printf("Jpegs Found: %i\n", jpgCount);


    fclose(inptr);
    fclose(inptr_EOF);
    fclose(outptr);

    printf("\n");
    return 0;
}