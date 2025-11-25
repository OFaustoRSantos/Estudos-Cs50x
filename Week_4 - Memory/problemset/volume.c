#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Finalizado! Ainda preciso submeter

// Number of bytes in .wav header
const int HEADER_SIZE = 44;

int main(int argc, char *argv[])
{
    // Verificar CLA
    // // Verificar FILE == WAV
    // // Verificar Output.wav
    // Check command-line arguments
    if (argc != 4)
    {
        printf("Usage: ./volume input.wav output.wav factor\n");
        return 1;
    }
    //char *ponto = strrchr(argv[1], '.');
    //if (strcmp(ponto, "wav") != 0) {
    //  printf("Usage: ./volume input.wav output.wav factor\n");
    //  return 1;
    //} else {
    //    printf("Usage: ./volume input.wav output.wav factor\n");
    //    return 1;
    //}


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

    float factor = atof(argv[3]); // What atof means?

    // TODO: Copy header from input file to output file

    uint8_t header[HEADER_SIZE]; // Defini para onde vai
    fread(header, HEADER_SIZE, 1, input);
    fwrite(header, HEADER_SIZE, 1, output); // por que não posso jogar direto fwrite(input, header_size, 1, output)

    // TODO: Read samples from input file and write updated data to output file
    int16_t buffer;
    // enquanto ter o que ler o while faz a alteração, Pq a diferença entre o size, pq um é 8 outro 16
    while (fread(&buffer, sizeof(int16_t), 1, input) != 0)
    {
        // Update volume of sample
        buffer *= factor;
        // Write updated sample to new file
        fwrite(&buffer, sizeof(int16_t), 1, output);
    }
    // Close files
    fclose(input);
    fclose(output);
}
