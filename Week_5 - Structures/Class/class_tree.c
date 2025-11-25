#include <stdio.h>
#include <stdlib.h>

// incompleto: Uma função ainda para fazer sozinho!

// Represents a node
typedef struct node
{
    int number;
    struct node *left; // menor
    struct node *right; // maior
    // Gasta mais memória, tem vantagens e desvantagens.
}
node;


void build_tree() // Sistema de criar tree - Criarei do zero otimizado. - Feito? 

void free_tree(node *root); // Sistema de liberação de memória
void print_tree(node *root); // Sistema de printar tree
bool Search(node *tree, int number); // sistema de Search - Bem simples

int main(void) // building tree, sistema incompleto, imagino por ser mais completo desenvolver
{
    // Tree of size 0 // abriu primeiro espaço
    node *tree = NULL;

    // Add number to list
    node *n = malloc(sizeof(node));
    if (n == NULL) // Sem espaço para criar
    {
        return 1;
    }
    // Virou o Root!
    n->number = 2;
    n->left = NULL;
    n->right = NULL;
    tree = n;

    // Add number to list
    n = malloc(sizeof(node));
    if (n == NULL)
    {
        free_tree(tree);
        return 1;
    }
    n->number = 1;
    n->left = NULL;
    n->right = NULL;
    tree->left = n;
     

    // Add number to list
    n = malloc(sizeof(node));
    if (n == NULL)
    {
        free_tree(tree);
        return 1;
    }
    n->number = 3;
    n->left = NULL;
    n->right = NULL;
    tree->right = n;

    // Print tree
    print_tree(tree);

    // Free tree
    free_tree(tree);
    return 0;
}

void free_tree(node *root)
{
    if (root == NULL)
    {
        return;
    }
    free_tree(root->left); // super massa
    free_tree(root->right); // super massa, uso de recursão de forma simples
    free(root);
    // 1° verifica, 2° manda limpar dois ptr associados, 3° limpa root,
    // deleta de "baixo" para "cima"
}

void print_tree(node *root)
{
    if (root == NULL)
    {
        return;
    }
    print_tree(root->left);
    printf("%i\n", root->number);
    print_tree(root->right);
}

// Aula do Cs50x, mostrou esse sistema, divide and conquer.
bool Search(node *tree, int number){
    if(tree == NULL){
        return false; // Chegou ao final da arvore.
    } else if(number < tree->number){ // N menor que numero no node
        return Search(*tree->left, number); // recursão
    } else if(number > tree->number){
        return Search(*tree->right, number);
    } else if( number == tree->number){
        return true;
    }
}