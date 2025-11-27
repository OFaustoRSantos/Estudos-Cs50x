#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(int argc, char *argv[])
{
    // Accept a single command-line argument
    if (argc != 2)
    {
        printf("Usage: ./recover FILE\n");
        return 1;
    }

    // Open the memory card
    FILE *card = fopen(argv[1], "r");

    // Create a buffer for a block of data
    uint8_t buffer[512];
    int contador = 0;
    char filename[8];
    FILE *img = NULL;

    // While there's still data left to read from the memory card
    while (fread(buffer, 1, 512, card) == 512)
    {
        // Create JPEGs from the data
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0){
            // Fechar arquivo antigo
            if(img != NULL){
                fclose(img);
            }
            // Abrir novo arquivo
            sprintf(filename, "%03i.jpg", contador); // Essa função é bem interessante
            img = fopen(filename, "w");

            if (img == NULL)
            {
                // Caso não consiga abrir o arquivo de saída
                fclose(card);
                printf("Não foi possível criar o arquivo de imagem.\n");
                return 1;
            }
            contador++;
        }

        // Escrever no novo arquivo
        if(img != NULL){
            fwrite(buffer, 1, 512, img);
        }


    }
    // Final do arquivo
    if (img != NULL)
    {
        fclose(img);
    }

    fclose(card);

    return 0;


}
