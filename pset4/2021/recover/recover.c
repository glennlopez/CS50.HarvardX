#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <cs50.h>
#include <stdbool.h>

// 0xff 0xd8 0xff (0xe0 - 0xef) = JPEG
int main(int argc, char *argv[])
{
    uint8_t buffer[512];
    int jpeg_counter = 0;
    char *filename = malloc(sizeof(char) * 30);
    FILE *jpeg = NULL;

    // Open a file pointer for reading
    FILE *input = fopen("card.raw", "r");
    if (input == NULL)
    {
        printf("Invalid file\n");
        return 1;
    }

    // Read through the raw data in 512 chunks
    while(fread(&buffer, sizeof(uint8_t), 512, input))
    {
        // If 512 chunk of data in buffer contains JPEG signature
        if ((buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff) && ((buffer[3] & 0xf0) == 0xe0))
        {
            // Generate a file name for the new jpeg file - ###.jpg starting at 000.jpg
            sprintf(filename, "%03i.jpg", jpeg_counter);

            // Open a new jpeg file pointer
            jpeg = fopen(filename, "w");

            // write the 512 chunks of data into the file pointer
            if(jpeg != NULL)
            {
                 fwrite(&buffer, sizeof(uint8_t), 512, jpeg);
            }

            // Increment the jpeg filename counter for the next jpeg file
            jpeg_counter++;
        }

        // If 512 chunk does not contain the signature of a JPEG file
        else
        {
            // keep writing 512 buffer to the jpeg file pointer as long as the file pointer isnt NULL
            if(jpeg != NULL)
            {
                fwrite(&buffer, sizeof(uint8_t), 512, jpeg);
            }
        }

        // TODO: free memory

    }

}