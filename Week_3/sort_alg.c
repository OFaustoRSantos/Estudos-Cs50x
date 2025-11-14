// Project to be able to use != sort algorithms to sort a list, also taking the time need to do it
#include <ctype.h>
#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

void Linear_Search(int lista[]);
void Binary_Search(int lista[]);

void bubblesort(int[]);
void selectionsort(int[]);
void quicksort(int[]);
void mergesort(int[]);

// ñ inserir command line arguments
int main(void){
    // get list of number
    int len = get_int("Qual o tamanho da lista - número de elementos? ");
    string s = get_string("Envie uma lista de números inteiros separados por , sem letras.");

    int n[len];
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
        } else if (isalpha(s[i]) != 0 || s[i] == "!"){
            printf("A lista não pode incluir letras ou sinais diferentes de , \n");
            return 1;
        } else if (s[i] == ' ' || s[i] > 10){
            printf("A lista só pode conter números e virgula.\n");
            return 1;
        }
    }
    string tipo_algoritmo;
    string algoritimo_selecionado;
    printf("Selecione que tipo de algoritimo deseja - S(Search) ou SRT(Sort)?\n");
    do{
        tipo_algoritmo = get_string("S ou SRT");
    } while (tipo_algoritmo != "S" || tipo_algoritmo != "SRT");

    if(tipo_algoritmo == "S"){
        printf("Selecione o algorítmo desejado: L(Linear Search), B(Binary Search) \n");
        do{
            algoritimo_selecionado = get_string("L ou B");
        } while (algoritimo_selecionado != "L" || algoritimo_selecionado != "B");
        if(algoritimo_selecionado == "L"){
            Linear_Search(n[]);
        } else{
            Binary_Search(n[]);
        }
    } else{
        printf("Selecione o algorítmo desejado: BSRT(BubbleSort), SSRT(SelectionSort), QSRT (QuickSort), MSRT(MergeSort) \n");
        do{
            algoritimo_selecionado = get_string("BSRT, SSRT, QSRT ou MSRT");
        } while (algoritimo_selecionado != "BSRT" || algoritimo_selecionado != "SSRT" || algoritimo_selecionado != "QSRT" || algoritimo_selecionado != "MSRT" );
        if(algoritimo_selecionado == "BSRT"){
            bubblesort(n[]);
        } if(algoritimo_selecionado == "SSRT") {
            selectionsort(n[]);
        } if(algoritimo_selecionado == "QSRT"){
            quicksort(n[]);
        }else{
            mergesort(n[]);
        }
    }
}

void Linear_Search(int lista[]){
    int interesse;
    
    do{ 
        interesse = get_int("Que número está procurando? ");
    } while(isalpha(interesse) != 0);

    for(int i = 0; i < len(lista[]); i++){
        if(lista[i] == interesse){
            printf("Seu número de interesse está na posição %i°. \n Encerrando sistema\n", i);
        }
    }
    printf("Seu número(%i) não está na lista!", interesse);

}

void Binary_Search(int lista[]){
    int interesse;
    int mid = len(lista[])/2;
    printf("Lembrando: Binary_Search SÓ funciona com listas já ORDENADAS\n");
    do{ 
        interesse = get_int("Que número está procurando? ");
    } while(isalpha(interesse) != 0);

    int max_mid = 1 + round(log2(len(lista)));
    int mid_atual = mid;
    for(int i = 0; i < max_mid; i++){
        if(lista[mid_atual] == interesse){
            printf("Encontramos seu número de interesse(%i), na posição %i° da lista\n", interesse, i);
        } 
        if(lista[mid_atual] > interesse){
            
        }else{
            
        }
    }
    printf("Seu número(%i) não está na lista!", interesse);
}

void bubblesort(int[]){

}
void selectionsort(int[]){

}
void quicksort(int[]){

}
void mergesort(int[]){

}