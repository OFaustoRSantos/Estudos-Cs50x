// Implements a dictionary's functionality
// competiu com o tideman para desafio mais difícil!

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <cs50.h>
#include <stdlib.h>

#include "dictionary.h"

int size_dict = 0;
bool locked_in[28][28][28][28][28][28][28][2];
// Represents a node in a hash table
typedef struct node
{
    int cara1;
    int cara2;
    string resto_word;
    struct node *next;
} node;

// Memory for numbers
node *list = NULL;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;

bool checker(const char *word, const int size_word){
    // Cheker amplo (Palavras 7+)
    const char *novo_texto = word + 7;
    node *ptr = list; // novo ponteiro
    while (ptr != NULL)
    {
        if(ptr->cara1 > word[0]){
            return false;
            break;
        }
        if(ptr->cara1 == word[0] && ptr->cara2 == word[1]){
            if(strcmp(ptr->resto_word, novo_texto) == 0)
            {
                return true;
            }
        }
        node *next = ptr->next;
        ptr = next;
    }
    return false;
}

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    int s_w = strlen(word);
    int chara[7];
    chara[0] = 27;chara[1] = 27;chara[2] = 27;chara[3] = 27;chara[4] = 27;chara[5] = 27;chara[6] = 27;
    
    // tirar casos comuns - a, the, and, or, of.
    if(strcmp(word, "a") == 0 || strcmp(word, "the") == 0 || strcmp(word, "of") == 0 || strcmp(word, "or") == 0 || strcmp(word, "and") == 0){
        return true;
    } if(s_w < 7) {
        for(int i = 0; i<s_w; i++){
            if(isalpha(word[i]) == 0){
                chara[i] = toupper(word[i]) - 'A';
            } else if(word[i] == 39){
                chara[i] = 26;
            } else{
                return false;
            }
        }
        if(locked_in[chara[0]][chara[1]][chara[2]][chara[3]][chara[4]][chara[5]][chara[6]][0] == true){
            return true;
        }
    }
    // Checker especial para palavras maiores
    else{
        for(int i = 0; i<s_w; i++){
            if(isalpha(word[i]) == 0){
                chara[i] = toupper(word[i]) - 'A';
            } else if(word[i] == 39){
                chara[i] = 26;
            } else{
                return false;
            }
        }
        if(locked_in[chara[0]][chara[1]][chara[2]][chara[3]][chara[4]][chara[5]][chara[6]][1] == true){
            checker(word, s_w);
        } else{
            return false;
        }
        
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function

    return toupper(word[0]) - 'A';
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    int chara[7];
    int s_w = 0;
    char str_max[38];
    char r_chara[40];
    
    FILE *arquivo = fopen(dictionary, "r");
    if(arquivo == NULL){
        return false;
    }
    char caractere;
    while ((caractere = fgetc(arquivo)) != EOF) {
        // Se o caractere lido for uma quebra de linha ('\n'), incrementa o contador do dict
        if (caractere == '\n') {
            if(s_w < 8){
                locked_in[chara[0]][chara[1]][chara[2]][chara[3]][chara[4]][chara[5]][chara[6]][0] = true;
                s_w = 0;
                chara[0] = 27;chara[1] = 27;chara[2] = 27;chara[3] = 27;chara[4] = 27;chara[5] = 27;chara[6] = 27;
                size_dict++;
            }else if (s_w > 8){
                locked_in[chara[0]][chara[1]][chara[2]][chara[3]][chara[4]][chara[5]][chara[6]][1] = true;
                node *n = malloc(sizeof(node));
                if (n == NULL)
                {
                    return false;
                }

                n->cara1 = chara[0];
                n->cara2 = chara[1];
                n->resto_word = malloc(s_w-7 + 1);
                n->resto_word = strcpy(n->resto_word, r_chara);
                
                n->next = NULL;
                for (node *ptr = list; ptr != NULL; ptr = ptr->next)
                {
                    if (ptr->next == NULL)
                    {
                        // Append node
                        ptr->next = n;
                        break;
                    }
                }
                s_w = 0;
                chara[0] = 27;chara[1] = 27;chara[2] = 27;chara[3] = 27;chara[4] = 27;chara[5] = 27;chara[6] = 27;
                r_chara[0] = '\0';
                size_dict++;
            } else{

            }
        } else{
            s_w++;
        }

        if(s_w < 8){
            if(caractere != 39){
                chara[s_w-1] = toupper(caractere) - 'A';
            } else{
                chara[s_w-1] = 26;
            }
            
        } else if (s_w>8)
        { 
            r_chara[s_w-1] = caractere;
            r_chara[s_w] = '\0';
        }

    }
    fclose(arquivo);
    return false;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return size_dict;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    // free
    node *ptr = list; // novo ponteiro
    while (ptr != NULL)
    {
        node *next = ptr->next;
        free(ptr);
        ptr = next;
    }
    return true;
}
