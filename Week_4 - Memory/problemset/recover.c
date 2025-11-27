#include <stdio.h>
#include <stdlib.h>

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
    int arquivo_aberto = 0; //verificar se tem algum arquivo em aberto
    
    // While there's still data left to read from the memory card
    while (fread(buffer, 1, 512, card) == 512)
    {
        // Create JPEGs from the data
        if ( buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & Oxf0) == Oxe0){
            arquivo_aberto += 1;
            // Fechar arquivo antigo
            if(arquivo_aberto > 0){
                fclose(filename);
            }
            // Abrir novo arquivo
            sprintf(filename, "%03i.jpg", arquivo_aberto);
            FILE *img = fopen(filename, "w");
        }
        // 
        // Escrever no novo arquivo
        if(arquivo_aberto != 0){
            fwrite(buffer, 1, 512, img);
        }

    }
    

    
}
