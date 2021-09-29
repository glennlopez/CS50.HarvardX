#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

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


    uint8_t *jpeg_finder = malloc(sizeof(uint8_t) * 4);
    uint8_t buffer;
    int index = 0;
    int jpeg_counter = 0;

    while(fread(&buffer, sizeof(uint8_t), 1, input))
    {
        jpeg_finder[index] = buffer; // store buffer to jpeg_block
        index++; // increment block index

        // reset block index
        if(index >= 4)
        {
            index = 0;
        }

        if (jpeg_finder[0] == 0xff && jpeg_finder[1] == 0xd8 && jpeg_finder[2] == 0xff)
        {
            printf("JPEG found!\n");
            printf("[0]: 0x%02x\n", jpeg_finder[0]);
            printf("[1]: 0x%02x\n", jpeg_finder[1]);
            printf("[2]: 0x%02x\n", jpeg_finder[2]);
            printf("[3]: 0x%02x\n", jpeg_finder[3]);
            printf("\n");
            printf("\n");
            jpeg_counter++;
        }

    }

    printf("Found %i JPEGs in RAW file.\n", jpeg_counter); // debug


    printf("\n");


    // FREE MEMORY
    //fclose(input);

}