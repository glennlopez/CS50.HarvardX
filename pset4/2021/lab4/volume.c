// Modifies the volume of an audio file

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Number of bytes in .wav header
const int HEADER_SIZE = 44;

int main(int argc, char *argv[])
{
    // Check command-line arguments
    if (argc != 4)
    {
        printf("Usage: ./volume input.wav output.wav factor\n");
        return 1;
    }

    // Open files and determine scaling factor
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    FILE *output = fopen(argv[2], "w");
    if (output == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    float factor = atof(argv[3]);



    /* TODO: Copy header from input file to output file */
    // allocate some heap memory for header
    uint8_t *header = malloc(sizeof(uint8_t) * HEADER_SIZE);

    // fread() the header into the heap
    uint8_t header_buffer;
    for (int i = 0; i < HEADER_SIZE; i++)
    {
        fread(&header_buffer, sizeof(uint8_t), 1, input);
        header[i] = header_buffer;
        fwrite(&header_buffer, sizeof(uint8_t), 1, output);
    }




    /* TODO: Read samples from input file and write updated data to output file */
    // Get the lenth of the wav file, for malloc
    int wav_size = 0;
    int16_t calcsize_buffer;
    fseek(input, HEADER_SIZE, SEEK_SET);
    while (fread(&calcsize_buffer, sizeof(int16_t), 1, input))
    {
        wav_size++;
    }

    // allocate memory on the heap to store the wav data
    int16_t *wavdata = malloc(sizeof(int16_t) * wav_size);

    // store the wav data chunk on the heap
    int16_t buffer;
    int index = 0;
    fseek(input, HEADER_SIZE, SEEK_SET);
    while (fread(&buffer, sizeof(int16_t), 1, input))
    {
        wavdata[index] = buffer;
        index++;
    }

    // make adjustments to the data chunk of the wave file
    for (int i = 0; i < wav_size; i++)
    {
        wavdata[i] *= factor;
    }

    // write wav data from the heap to the copy file pointer
    fseek(output, HEADER_SIZE, SEEK_SET);
    fwrite(wavdata, sizeof(int16_t), wav_size, output);



    // Memory management
    fclose(input);
    fclose(output);
    free(wavdata);
    free(header);
}
