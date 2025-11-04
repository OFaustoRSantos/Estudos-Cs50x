// Project to be able to use != sort algorithms to sort a list, also taking the time need to do it
#include <ctype.h>
#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

string bubblesort(int[]);
string selectionsort(int[]);
string mergesort(int[]);

// ñ inserir command line arguments
int main(void){
    // get list of number
    string s = get_string("Envie uma lista de números inteiros separados por , sem letras. \n");

    int n[(strlen(s)/2)];
    int last_position = 0;
    int last_number = -1;
    int final_number = 0;
    // convertendo string numa array de números - falta testar
    for(int i = 0; i< strlen(s); i++;){
        if(s[i] == ','){
            for(i-last_position != 0){
                final_number = final_number + s[last_position]*10^(i-last_position-1);
                last_position++;
            }
            last_position = i+1;
            last_number++;
            n[last_number] = final_number;
            final_number = 0;
        } else if (isalpha(s[i]) != 0 || s[i]){
            printf("A lista não pode incluir letras ou sinais diferentes de ,");
            return 0;
        } else if (s[i] == ' ' || s[i] > 10){
            printf("A lista só pode conter números e virgula");
            return 0;
        }
    }


}