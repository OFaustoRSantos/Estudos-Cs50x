#include <ctype.h>
#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int index_calculate(string);

int main(){
    string = get_string("Text: ");

    float index = index_calculate(string);
    if (round(index) > 16){
        print("grade %i+\n", round(index));
    } else if (round(index) < 1){
        print("Before grade 1\n");
    } else{
        print("grade %i\n", round(index));
    }
    
}

int index_calculate(string){
    // mathematical relationship between the number of words and the number of spaces.
    int letters = 0;
    int setences = 0;
    int word = 0;
    for (int i = 0; i<strlen(string); i++){
        if(string[i] == ' '){
            word++;
        }else if (string[i] == '.'){
            setences++;
        } else {
            letters++;
        }
    }
    float avg_letters = 0;
    float avg_setences = 0;
    // How count average number of letters per 100 words in the text
    avg_letters = letters/(float(word/100));
    // How coun average number of sentences per 100 words in the text.
    avg_setences = setences/(float(word/100));
    // Apply formula
    float index = 0;
    index = 0.0588 * avg_letters - 0.296 * avg_setences - 15.8
    return index;
}
