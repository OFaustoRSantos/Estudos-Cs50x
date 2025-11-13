// Explained more about File I/O

#include <stdio.h>

int main(int argc, string argv[]){
    if(argc != 2){
        printf("Usage: ./section filename.extension\n");
        return 1;
    }

    FILE *input = fopne(argv[1], "r");

    uint8_t buffer[4];
    //uint8_t -> A size of a int/ a byt
    // [4] number of bytes

    uint8_t signature[] ={0x25,0x50,0x44,0x46};

    //Read firsts 4 bytes from the file
    fread(buffer, sizeof(uint8_t), 4, input);

    for(int i = 0; i < 3; i++){
        if(buffer[i] != signature[i]){
            printf("The document don't have the %i signature in correct place, so isn't a pdf\n", i);
        }
        // each document have a byte signature, so we can create a document indentifier
        
    }
    fclose(input);
}