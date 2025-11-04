
#include <ctype.h>
#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

struct s_candidate{
    string name;
    int votes = 0;
}

void print_winner(int argc);
int vote(int n_votes, int argc);

int main(int argc, string argv[]){
    if (argc < 2)
    {
        printf("Usage: ./substitution [candidate ...] \n");
        return 1;
    }
    if(argc > 10){
        printf("Please include max 9 candidates.\n");
        return 1;
    } 
    s_candidate candidate[(argc - 1)];
    for(int i = 0; i < (argc+1); i++;){
        candidate[i] = argv[(i+1)];
    }

    int n_votes = get_int("Number of voters: ");

    vote(n_votes);

    print_winner(argc)
}

int vote(int n_votes, int argc){
    string vote = get_string("Vote: ");
    for(int i = 0; i < (argc-1); i++;){
        if(vote == candidate[i].name){
            candidate[i].votes++;
        }
    }
    n_votes--;
    vote(n_votes, argc);
}

void print_winner(int argc)
{
    int r_sort[(argc-1)];
    // sort candidatos:
    // Printar de maior número, caso
    return;
}