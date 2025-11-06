// OBS.: O codigo está fora da estrutura pedida no Cs50x, pois comecei a programar sem o documento com uma formatação esperada do código
// Entretanto está funcionando completamente.
#include <ctype.h>
#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

typedef struct
{
    string name;
    int votes;
} candidates;

void print_winner(int argc, candidates candidate[], string argv[]);
void vote(int n_votes, int argc, candidates candidate[]);

int main(int argc, string argv[]){
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }
    if(argc > 10){
        printf("Maximum number of candidates is 9\n");
        return 1;
    }
    candidates candidate[argc - 1];
    for(int i = 0; i < (argc - 1); i++){
        candidate[i].name = argv[(i+1)];
        candidate[i].votes = 0;
    }


    int n_votes = get_int("Number of voters: ");

    vote(n_votes, argc, candidate);

    print_winner(argc, candidate, argv);
}

void vote(int n_votes, int argc, candidates candidate[]){
    string votes = get_string("Vote: ");
    int candidate_avaible = 0;
    for(int i = 0; i < (argc-1); i++){
        if(strcmp(votes, candidate[i].name) == 0){
            candidate[i].votes++;
            candidate_avaible++;
        }
    }
    if (candidate_avaible == 0){
        printf("Invalid vote.\n");
    }
    n_votes--;
    if(n_votes != 0){
        vote(n_votes, argc, candidate);
    }
}

void print_winner(int argc, candidates candidate[], string argv[])
{
    int max_votes = 0;

    for (int i = 0; i < argc - 1; i++)
    {
        if (candidate[i].votes > max_votes)
        {
            max_votes = candidate[i].votes;
        }
    }

    printf("The winner is:\n");
    for (int i = 0; i < argc - 1; i++)
    {
        if (candidate[i].votes == max_votes)
        {
            printf("%s\n", candidate[i].name);
        }
    }
}
