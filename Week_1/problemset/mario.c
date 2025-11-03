#include <stdio.h>
#include <cs50.h>

int get_height();

int main(void){
    int h;
    do{
        h = get_int("How big will be the pyramid? ");
    }
    while(h < 1 || h > 8);

    for(int i = 1; i < h + 1; i++)
    {
        // criar espaços
        for(int x = h; x > i; x--)
        {
            printf(" ");
        }
        for(int j = 0; j < i; j++)
        {
            printf("#");
        }
        printf("  ");
        for(int x = 0; x < i; x++)
        {
            printf("#");
        }

        printf("\n");
    }

}

