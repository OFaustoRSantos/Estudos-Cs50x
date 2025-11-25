//Não foi feito na aula, mas quero criar do zero
#include <ctype.h>
#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void add_name();
void search_name();
void print_full_dic();
int found_hash_pos(const char *word);

int main(){
    // Sistema escolher função:
    

}

int found_hash_pos(const char *word)
{
    return toupper(word[0]) - 'A'; // Position in array!
    // While A will be first(0), B (1) ...
}