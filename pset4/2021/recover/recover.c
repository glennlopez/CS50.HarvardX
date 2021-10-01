#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <cs50.h>
#include <stdbool.h>

// 0xff 0xd8 0xff (0xe0 - 0xef) = JPEG

int main(int argc, char *argv[])
{

    // open a file pointer for reading
    FILE *input = fopen("card.raw", "r");
    if (input == NULL)
    {
        printf("Invalid file\n");
        return 1;
    }


    uint8_t buffer[512];
    int jpeg_counter = 0;
    char *filename = malloc(sizeof(char) * 30);
    FILE *jpeg = NULL;


    // read through the raw data in 512 chunks
    while(fread(&buffer, sizeof(uint8_t), 512, input))
    {
        // If JPEG is found
        if ((buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff) && ((buffer[3] & 0xf0) == 0xe0))
        {
            //debug
            printf("JPEG found!\n");
            printf("[0]: 0x%02x\n", buffer[0]);
            printf("[1]: 0x%02x\n", buffer[1]);
            printf("[2]: 0x%02x\n", buffer[2]);
            printf("[3]: 0x%02x\n", buffer[3]);
            printf("\n");
            printf("\n");

            // generate a file name - ###.jpg starting at 000.jpg
            sprintf(filename, "%03i.jpg", jpeg_counter);

            // open a new file using the filename
            jpeg = fopen(filename, "w");

            // write the bytes into the file pointer
            fwrite(&buffer, sizeof(uint8_t), 512, jpeg);

            jpeg_counter++;
        }
        // already found a jpeg
        else
        {
            // keep writing
            if(jpeg != NULL)
            {
                fwrite(&buffer, sizeof(uint8_t), 512, jpeg);
            }


        }



    }

    printf("Found %i JPEGs in RAW file.\n", jpeg_counter); // debug


    printf("\n");


    // FREE MEMORY
    //fclose(input);

}