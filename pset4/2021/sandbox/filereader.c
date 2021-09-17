// uint8_t -> unsigned int 8bit large (used for representing a generic bite of data)
// int16_t -> signed int 16bit large (used for representive sound sample)
// fread(), fwrite() -> used for reading and writing files
//

#include <cs50.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>


int main()
{

    /* INIT FILE POINTERS */
    // open wave file for reading
    FILE *wav = fopen("input.wav", "r");
    if(wav == NULL)
    {
        printf("Invalid file\n");
    }

    // open wave file for writing
    FILE *copy = fopen("new.wav", "w");
    if(copy == NULL)
    {
        printf("Invalid copy\n");
    }






    /* COPY THE WAV HEADER */
    // read the wav file header (44 bytes long)
    const int HEADER_SIZE = 44;
    uint8_t *header = malloc(sizeof(uint8_t) * 44);
    uint8_t header_buffer;


    // fread() the header file and place the values in *head
    printf("Buffer:\n");
    for(int i = 0; i < HEADER_SIZE; i++)
    {
        fread(&header_buffer, sizeof(uint8_t), 1, wav);
        header[i] = header_buffer;
        printf("0x%02x ", header_buffer); // debug - console print hex value stored in the header_buffer
        fwrite(&header_buffer, sizeof(uint8_t), 1, copy);
    }
    printf("\n");

    // DEBUG - Show values of header
    printf("Header:\n");
    for(int i = 0; i < HEADER_SIZE; i++)
    {
        printf("0x%02x ", header[i]); // debug - console print hex value stored in the header
    }
    printf("\n");
    printf("\n");
    printf("\n");



    // get wave file size for wave file malloc
    fseek(wav, HEADER_SIZE, SEEK_SET);
    int wav_size = 0;
    int16_t calcsize_buffer;
    fseek(wav, HEADER_SIZE, SEEK_SET);
    while(fread(&calcsize_buffer, sizeof(int16_t), 1, wav))
    {
        wav_size++;
    }

    // allocate memory on the heap to store the wav data
    int16_t *wavdata = malloc(sizeof(int16_t) * wav_size);






    /* COPY THE WAV DATA */


    // store wav data on the heap
    int16_t buffer;
    int index = 0;
    fseek(wav, HEADER_SIZE, SEEK_SET);
    while(fread(&buffer, sizeof(int16_t), 1, wav))
    {
        wavdata[index] = buffer;
        index++;
    }


    // make adjustments to the data chunk of the wave file
    double volume = 2;
    for(int i = 0; i < wav_size; i++)
    {
        wavdata[i] *= volume;
    }


    // write wav data from the heap to the copy file pointer
    fseek(copy, HEADER_SIZE, SEEK_SET);
    fwrite(wavdata, sizeof(int16_t), wav_size, copy);




    /* CLEAR MEMORY */
    fclose(wav);
    fclose(copy);
    free(wavdata);

}