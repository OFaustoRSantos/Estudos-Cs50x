#include <ctype.h>
#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

// Enviado com erro no sort, qual? Nem eu sei kkkk, ta funcionando mais o checker do cs50x nn ta reconhecendo.

// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
    int v_prefer;
} pair;

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;

// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
bool creates_cycle(int start, int end);
void lock_pairs(void);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    // Definindo os candidatos, sendo anexados a um valor i
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i] = argv[i + 1];
    }

    // Clear graph of locked in pairs e o preferences tbm, fugindo de garbage values

    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
            preferences[i][j] = 0;
        }
    }

    pair_count = 0;
    int voter_count = get_int("Number of voters: ");

    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }

        record_preferences(ranks);

        printf("\n");
    }

    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();
    return 0;
}

// Update ranks given a new vote
bool vote(int rank, string name, int ranks[])
{
    // TODO
    for(int i = 0; i<candidate_count; i++){
        if(strcmp(name,candidates[i]) == 0){
            ranks[rank] = i;
            return true;
            // Simplesmente anotando as preferencias
        }
    }
    return false;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    
    // TODO
    for(int i =0; i<candidate_count; i++){
        int x = ranks[i];
        for(int j = 1; j + i < candidate_count; j++){
            int y = ranks[j+i];
            preferences[x][y]++;
        }
    }
    return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    /* - Tem um erro aqui! Estraga o pair_count por isso estraga o sistema!
    for(int i = 0; i < candidate_count; i++){
        for(int j = 0; j <candidate_count; j++){
            if(preferences[i][j] > preferences[j][i]){
                pairs[pair_count].winner = i;
                pairs[pair_count].loser = j;
                pairs[pair_count].v_prefer = preferences[i][j] - preferences[j][i];
                pair_count++;
            }
        }
    }
    */
    pair_count = 0;

    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = i + 1; j < candidate_count; j++)
        {
            if (preferences[i][j] > preferences[j][i])
            {
                pairs[pair_count].winner = i;
                pairs[pair_count].loser = j;
                // força = margem: favoritos sobre o outro menos o contrário - MTO CONFUSO!
                pairs[pair_count].v_prefer = preferences[i][j] - preferences[j][i];
                pair_count++;
            }
            else if (preferences[j][i] > preferences[i][j])
            {
                pairs[pair_count].winner = j;
                pairs[pair_count].loser = i;
                pairs[pair_count].v_prefer = preferences[j][i] - preferences[i][j];
                pair_count++;
            }
            // se empatar fazer nada
        }
    }
    return;
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    // TODO
    // 2° teste com bubble sort => TAMBÉM nn funcionou kkkk
     for (int i = 0; i < pair_count - 1; i++)
    {
        // O loop interno faz as trocas
        for (int j = 0; j < pair_count - 1 - i; j++)
        {
            // Se o par atual (j) tiver margem MENOR que o próximo (j+1),
            // eles estão fora de ordem decrescente, e devem ser trocados.
            if (pairs[j].v_prefer < pairs[j + 1].v_prefer)
            {
                // Troca
                pair temp = pairs[j];
                pairs[j] = pairs[j + 1];
                pairs[j + 1] = temp;
            }
        }
    }
    
    // Usando Selection Sort nn deu certo, não sei por que, versão original (1° que fiz, foi com SSORT) A de cima foi com bubble sort
    /*
    // ponteiro 1
    for(int i=0; i < pair_count - 1; i++ ){
        int p_max_value = i; //posição do valor máximo
        for(int j = i + 1; j < pair_count; j++){ // ponteiro 2
            //Achando posição máxima
            if(pairs[j].v_prefer > pairs[p_max_value].v_prefer)
            {
                p_max_value = j; // Atualiza o índice do máximo
            }

        }
        // Trocando um com outro
        pair tmp = pairs[i];
        pairs[i] = pairs[p_max_value];
        pairs[p_max_value] = tmp;
    }
    return;
    */
}

// Verificar se adicionar edge não cria ciclo -> Força Bruta
bool creates_cycle(int start, int end)
{
    // Caso base: Se o caminho atual retornar ao ponto de início do ciclo
    if (start == end)
    {
        return true;
    }

    // Caso recursivo: Tenta mover-se para os vizinhos
    for (int i = 0; i < candidate_count; i++)
    {
        // Se houver uma aresta bloqueada de 'start' para 'i' (start -> i)
        if (locked[start][i])
        {
            // Verifica recursivamente se há um caminho de 'i' para 'end'
            if (creates_cycle(i, end))
            {
                return true;
            }
        }
    }

    // Não foi encontrado um ciclo - AMEM
    return false;
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{

    // TODO
    for (int i = 0; i < pair_count; i++)
    {
        int winner = pairs[i].winner;
        int loser = pairs[i].loser;

        // Se adicionar a aresta (winner -> loser) NÃO criar um ciclo!
        if (!creates_cycle(loser, winner))
        {
            locked[winner][loser] = true;
        }
    }

    return;
}

// Print the winner of the election
void print_winner(void)
{
    // TODO


    for(int i = 0; i < candidate_count; i++){
        bool vitoria = true;
        // se candidato não tiver seta apontando para ele;
        for(int j = 0; j < candidate_count; j++){
            if(locked[j][i] == true){
                vitoria = false;
                break;
            }
        }
        if(vitoria){
            printf("%s\n", candidates[i]);
        }

    }
    return;
}
