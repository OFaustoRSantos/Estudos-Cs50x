#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int count_point(string s);
int main(){
    string s1 = get_string("Player1:  ");
    string s2 = get_string("Player2:  ");
    printf("Hello, %s\n", s);
    // count number of caracters

    int P1 = count_point(s1);
    int P2 = count_point(s2);

    if (P1 > P2){
        printf('Player 1 wins!\n');
    }
    else if(P2 > P1){
        printf('Player 2 wins!\n');
    }
    else {
        printf('Tie! \n');
    }

}

int count_point(string s){

    int score;
    for (int i = 0, len = strlen(s); i < len; i++)
    {
        if (isalpha(s[i])){

        }
        else if (isupper(s[i]))
        {
            score += POINTS[s[i] - 'A'];
        }
        else if (islower(s[i]))
        {
            score += POINTS[s[i] - 'a'];
        }
    }
    return score;
}
