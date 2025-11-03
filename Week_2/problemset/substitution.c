#include <ctype.h>
#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

string ciphertext(string);
int arr[26];
int erro = 0;
int main(int argc, string argv[])
{
    if (argc!= 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    if(strlen(argv[1]) != 26){
        printf("Key must contain 26 characters.\n");
        return 1;
    } 
    for(int i = 0; i < strlen(argv[1]); i++;){
        if(!isalpha(argv[1])){
            printf("Key must contain only alpha.\n");
            return 1;
        }
        if(erro == 1){
            return 1;
        }
        switch (toumper(argv[1][i])) {
                case 'A':
                    arr[0]++;
                    if (arr[0] > 1) {
                        printf("  Erro: Caractere repetiu.\n");
                        erro = 1;
                    }
                    break;
                case 'B':
                    arr[1]++;
                    if (arr[1] > 1) {
                        printf("  Erro: Caractere repetiu.\n");
                        erro = 1;
                    }
                    break;
                case 'C':
                    arr[2]++;
                    if (arr[2] > 1) {
                        printf("  Erro: Caractere repetiu.\n");
                        erro = 1;
                    }
                    break;
                case 'D':
                    arr[3]++;
                    if (arr[3] > 1) {
                        printf("  Erro: Caractere repetiu.\n");
                        erro = 1;
                    }
                    break;
                case 'E':
                    arr[4]++;
                    if (arr[4] > 1) {
                        printf("  Erro: Caractere repetiu.\n");
                        erro = 1;
                    }
                    break;
                case 'F':
                    arr[5]++;
                    if (arr[5] > 1) {
                        printf("  Erro: Caractere repetiu.\n");
                        erro = 1;
                    }
                    break;
                case 'G':
                    arr[6]++;
                    if (arr[6] > 1) {
                        printf("  Erro: Caractere repetiu.\n");
                        erro = 1;
                    }
                    break;
                case 'H':
                    arr[7]++;
                    if (arr[7] > 1) {
                        printf("  Erro: Caractere repetiu.\n");
                        erro = 1;
                    }
                    break;
                case 'I':
                    arr[8]++;
                    if (arr[8] > 1) {
                        printf("  Erro: Caractere repetiu.\n");
                        erro = 1;
                    }
                    break;
                case 'J':
                    arr[9]++;
                    if (arr[9] > 1) {
                        printf("  Erro: Caractere repetiu.\n");
                        erro = 1;
                    }
                    break;
                case 'K':
                    arr[10]++;
                    if (arr[10] > 1) {
                        printf("  Erro: Caractere repetiu.\n");
                        erro = 1;
                    }
                    break;
                case 'L':
                    arr[11]++;
                    if (arr[11] > 1) {
                        printf("  Erro: Caractere repetiu.\n");
                        erro = 1;
                    }
                    break;
                case 'M':
                    arr[12]++;
                    if (arr[12] > 1) {
                        printf("  Erro: Caractere repetiu.\n");
                        erro = 1;
                    }
                    break;
                case 'N':
                    arr[13]++;
                    if (arr[13] > 1) {
                        printf("  Erro: Caractere repetiu.\n");
                        erro = 1;
                    }
                    break;
                case 'O':
                    arr[14]++;
                    if (arr[14] > 1) {
                        printf("  Erro: Caractere repetiu.\n");
                        erro = 1;
                    }
                    break;
                case 'P':
                    arr[15]++;
                    if (arr[15] > 1) {
                        printf("  Erro: Caractere repetiu.\n");
                        erro = 1;
                    }
                    break;
                case 'Q':
                    arr[16]++;
                    if (arr[16] > 1) {
                        printf("  Erro: Caractere repetiu.\n");
                        erro = 1;
                    }
                    break;
                case 'R':
                    arr[17]++;
                    if (arr[17] > 1) {
                        printf("  Erro: Caractere repetiu.\n");
                        erro = 1;
                    }
                    break;
                case 'S':
                    arr[18]++;
                    if (arr[18] > 1) {
                        printf("  Erro: Caractere repetiu.\n");
                        erro = 1;
                    }
                    break;
                case 'T':
                    arr[19]++;
                    if (arr[19] > 1) {
                        printf("  Erro: Caractere repetiu.\n");
                        erro = 1;
                    }
                    break;
                case 'U':
                    arr[20]++;
                    if (arr[20] > 1) {
                        printf("  Erro: Caractere repetiu.\n");
                        erro = 1;
                    }
                    break;
                case 'V':
                    arr[21]++;
                    if (arr[21] > 1) {
                        printf("  Erro: Caractere repetiu.\n");
                        erro = 1;
                    }
                    break;
                case 'W':
                    arr[22]++;
                    if (arr[22] > 1) {
                        printf("  Erro: Caractere repetiu.\n");
                        erro = 1;
                    }
                    break;
                case 'X':
                    arr[23]++;
                    if (arr[23] > 1) {
                        printf("  Erro: Caractere repetiu.\n");
                        erro = 1;
                    }
                    break;
                case 'Y':
                    arr[24]++;
                    if (arr[24] > 1) {
                        printf("  Erro: Caractere repetiu.\n");
                        erro = 1;
                    }
                    break;
                case 'Z':
                    arr[25]++;
                    if (arr[25] > 1) {
                        printf("  Erro: Caractere repetiu.\n");
                        erro = 1;
                        
                    }
                    break;

        }
    }

    string s = get_string("plaintext: ");

    string new_s = ciphertext(s, argv[1]);
    printf("ciphertext: %s\n", new_s);
    return 0;
    
}

string ciphertext(string s, string key){
    string n_str = s;
    for(int i = 0; i < strlen(string); i++;){
        if(islower(s[i])){
            switch (toupper(s)) {
                case 'A':
                    n_str[i] = tolower(argv[1][0]);
                    break;
                case 'B':
                    n_str[i] = tolower(argv[1][1]);
                    break;
                case 'C':
                    n_str[i] = tolower(argv[1][2]);
                    break;
                case 'D':
                n_str[i] = tolower(argv[1][3]);
                break;
                case 'E':
                n_str[i] = tolower(argv[1][4]);
                break;
                case 'F':
                n_str[i] = tolower(argv[1][5]);
                break;
                case 'G':
                n_str[i] = tolower(argv[1][6]);
                break;
                case 'H':
                    n_str[i] = tolower(argv[1][7]);
                    break;
                case 'I':
                n_str[i] = tolower(argv[1][8]);
                    break;
                case 'J':
                n_str[i] = tolower(argv[1][9]);
                    break;
                case 'K':
                n_str[i] = tolower(argv[1][10]);
                    break;
                case 'L':
                n_str[i] = tolower(argv[1][11]);
                    break;
                case 'M':
                n_str[i] = tolower(argv[1][12]);
                    break;
                case 'N':                
                    n_str[i] = tolower(argv[1][13]);
                    break;
                case 'O':
                n_str[i] = tolower(argv[1][14]);
                    break;
                case 'P':
                n_str[i] = tolower(argv[1][15]);
                    break;
                case 'Q':
                n_str[i] = tolower(argv[1][16]);
                    break;
                case 'R':
                n_str[i] = tolower(argv[1][17]);
                    break;
                case 'S':
                n_str[i] = tolower(argv[1][18]);
                    break;
                case 'T':
                n_str[i] = tolower(argv[1][19]);
                    break;
                case 'U':
                n_str[i] = tolower(argv[1][20]);
                    break;
                case 'V':
                n_str[i] = tolower(argv[1][21]);
                    break;
                case 'W':
                n_str[i] = tolower(argv[1][22]);
                    break;
                case 'X':
                n_str[i] = tolower(argv[1][23]);
                    break;
                case 'Y':
                n_str[i] = tolower(argv[1][24]);
                    break;
                case 'Z':
                n_str[i] = tolower(argv[1][25]);
                    break;
                default:
                    n_str[i] = s[i]
                    break
        }
        } 
        else{
        switch (s) {
            case 'A':
                n_str[i] = argv[1][0];
                break;
            case 'B':
                n_str[i] = argv[1][1];
                break;
            case 'C':
                n_str[i] = argv[1][2];
                break;
            case 'D':
            n_str[i] = argv[1][3];
            break;
            case 'E':
            n_str[i] = argv[1][4];
            break;
            case 'F':
            n_str[i] = argv[1][5];
            break;
            case 'G':
            n_str[i] = argv[1][6];
            break;
            case 'H':
                n_str[i] = argv[1][7];
                break;
            case 'I':
            n_str[i] = argv[1][8];
                break;
            case 'J':
            n_str[i] = argv[1][9];
                break;
            case 'K':
            n_str[i] = argv[1][10];
                break;
            case 'L':
            n_str[i] = argv[1][11];
                break;
            case 'M':
            n_str[i] = argv[1][12];
                break;
            case 'N':                
                n_str[i] = argv[1][13];
                break;
            case 'O':
            n_str[i] = argv[1][14];
                break;
            case 'P':
            n_str[i] = argv[1][15];
                break;
            case 'Q':
            n_str[i] = argv[1][16];
                break;
            case 'R':
            n_str[i] = argv[1][17];
                break;
            case 'S':
            n_str[i] = argv[1][18];
                break;
            case 'T':
            n_str[i] = argv[1][19];
                break;
            case 'U':
            n_str[i] = argv[1][20];
                break;
            case 'V':
            n_str[i] = argv[1][21];
                break;
            case 'W':
            n_str[i] = argv[1][22];
                break;
            case 'X':
            n_str[i] = argv[1][23];
                break;
            case 'Y':
            n_str[i] = argv[1][24];
                break;
            case 'Z':
            n_str[i] = argv[1][25];
                break;
            default:
                n_str[i] = s[i]
                break
        }
        }
    }


}