#include <stdio.h>
#include <cs50.h>

int main(void){
    long cardnumber;
    do{
        cardnumber = get_long("The cardnumber is? ");
    }
    while (cardnumber < 8000);

    // transformando em array
    // variáveis
    long num = cardnumber;
    long temp = num;
    int digits = 0; // n de index

    // Count how many digits the number has
    while (temp > 0) {
        temp /= 10; // dividir por 10
        digits++;
    }
    if((digits == 14) || (digits < 12) || (digits > 17)){
        printf("INVALID\n");
        return 0;
    }

    int arr[digits];

    // somas do algoritmo de verificação
    int sum1[digits];
    // Fill the array from the end
    for (int i = digits - 1; i >= 0; i--) {
        arr[i] = num % 10; //resto
        num /= 10;
    }
    // Print the array
    int x = 0;
    int sumtotal = 0;
    bool valid = false;
    for (int i = digits - 1; i > -1; i--) {
        if (x%2 == 1){
            if((arr[i]*2)/10 >= 1){
                sum1[x] = (arr[i]*2)/10 + (arr[i]*2)%10;
            }
            else{
                sum1[x] = arr[i]*2;
            }
        }
        else{sum1[x] = arr[i];}
        sumtotal += sum1[x];
        x++;
    }
    if((sumtotal%10 == 0)){
        valid = true;
    }
    else{
        printf("INVALID\n");
    }
        if(arr[0] == 3 & digits == 15){
            if(arr[1] == 7 || arr[1] == 4 )
            {
            if(valid == true){printf("AMEX\n");}
            }else{
            printf("INVALID\n");
        }
        }
        else if((arr[0] == 4) & (digits == 13 || digits == 16) ){
            if(valid == true){ printf("VISA\n");}
        }
        else if(arr[0] == 5){
            if(arr[1] < 6 & arr[1] > 0 ){
                if(valid == true){printf("MASTERCARD\n");}
            }
            else{
            printf("INVALID\n");
            }
        }
        else{
            printf("INVALID\n");
        }



}