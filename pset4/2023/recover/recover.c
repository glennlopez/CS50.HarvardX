#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <cs50.h>
#include <stdbool.h>
/*
    SPECIFICATIONS
    Implement your program in a file called recover.c in a directory called recover.
    Your program should accept exactly one command-line argument, the name of a forensic image from which to recover JPEGs.
    If your program is not executed with exactly one command-line argument, it should remind the user of correct usage, and main should return 1.
    If the forensic image cannot be opened for reading, your program should inform the user as much, and main should return 1.
    The files you generate should each be named ###.jpg, where ### is a three-digit decimal number, starting with 000 for the first image and counting up.
    Your program, if it uses malloc, must not leak any memory.
*/

// 0xff 0xd8 0xff (0xe0 - 0xef) = JPEG
int main(int argc, char *argv[])
{
    uint8_t buffer[512];
    int jpeg_counter = 0;
    char *filename = malloc(sizeof(char) * 30);
    FILE *jpeg = NULL;

    // Program accepts only one command line argument
    if (argc != 2)
    {
        printf("Usage: ./recover <file>\n");
        return 1;
    }

    // Open the raw data
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("File invalid or not found.\n");
        return 1;
    }

    // Read through the raw data in 512 chunks
    while (fread(&buffer, sizeof(uint8_t), 512, input))
    {
        // If 512 chunk of data in buffer contains JPEG signature
        if ((buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff) && ((buffer[3] & 0xf0) == 0xe0))
        {
            // close the previous jpeg file pointer if it exists
            if (jpeg != NULL)
            {
                fclose(jpeg);
            }

            // Generate a file name for the new jpeg file - ###.jpg starting at 000.jpg
            sprintf(filename, "%03i.jpg", jpeg_counter);

            // Open a new jpeg file pointer
            jpeg = fopen(filename, "w");

            // write the 512 chunks of data into the file pointer
            if (jpeg != NULL)
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
            if (jpeg != NULL)
            {
                fwrite(&buffer, sizeof(uint8_t), 512, jpeg);
            }
        }
    }

    // Free memory
    if (jpeg != NULL)
    {
        fclose(jpeg);
    }
    free(filename);
    fclose(input);

}