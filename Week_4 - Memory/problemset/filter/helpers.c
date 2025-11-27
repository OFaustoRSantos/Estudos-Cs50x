#include "helpers.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // avarage of values
    for (int i = 0; i < height; i++) // para cada coluna
    {
        for (int j = 0; j < width; j++) // para cada linha
        {
            int average = (image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3; // calcular a média dos valores
            image[i][j].rgbtBlue = average; // atribuir a média ao valor azul
            image[i][j].rgbtGreen = average; // atribuir a média ao valor verde
            image[i][j].rgbtRed = average; // atribuir a média ao valor vermelho
        }
    }
    return; // retornar a função
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++) // para cada coluna
    {
        for (int j = 0; j < width; j++) // para cada linha
        {
            RGBTRIPLE temp = image[i][j]; // armazenar o valor atual
            image[i][j] = image[i][width - j - 1];
            image[i][width - j - 1] = temp; // Por que o -1?
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++){
        for (int j = 0; j < width; j++){
            int sumBlue = 0;
            int sumGreen = 0;
            int sumRed = 0;
            for(int x = -1; x<1; x++){
                for(int y=-1; y<2; y++){
                    sumBlue += image[i+x][j+y].rgbtBlue;
                    sumGreen += image[i+x][j+y].rgbtGreen;
                    sumRed += image[i+x][j+y].rgbtRed;
                }
            }
            image[i][j].rgbtBlue = sumBlue/9; 
            image[i][j].rgbtGreen = sumGreen/9; 
            image[i][j].rgbtRed = sumRed/9;
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    int Gx[3][3];
    int Gy[3][3];
    
        for(int j = 0; j < 3; j++){
            Gx[0][j] = -1 + j;
            Gx[1][j] = -2 + 2*j;
            Gx[2][j] = -1 + j;

            Gy[j][0] = -1 + j;
            Gy[j][1] = -2 + 2*j;
            Gy[j][2] = -1 + j;
        }

    
    for (int i = 0; i < height; i++){
        for (int j = 0; j < width; j++){
            int Gy_sumBlue = 0;
            int Gy_sumGreen = 0;
            int Gy_sumRed = 0;
            int Gx_sumBlue = 0;
            int Gx_sumGreen = 0;
            int Gx_sumRed = 0;
            for(int x = -1; x<1; x++){
                for(int y=-1; y<2; y++){
                    Gx_sumBlue += (image[i+x][j+y].rgbtBlue) * Gx[i+x][j+y];
                    Gx_sumGreen += (image[i+x][j+y].rgbtGreen) * Gx[i+x][j+y];
                    Gx_sumRed += (image[i+x][j+y].rgbtRed) * Gx[i+x][j+y];
                    Gy_sumBlue += (image[i+x][j+y].rgbtBlue) * Gy[i+x][j+y];
                    Gy_sumGreen += (image[i+x][j+y].rgbtGreen) * Gy[i+x][j+y];
                    Gy_sumRed += (image[i+x][j+y].rgbtRed) * Gy[i+x][j+y];
                }
            }
            image[i][j].rgbtBlue = (Gx_sumBlue^2 + Gy_sumBlue^2)^(1/2); 
            image[i][j].rgbtGreen = (Gx_sumGreen^2 + Gy_sumGreen^2)^(1/2); 
            image[i][j].rgbtRed = (Gx_sumRed^2 + Gy_sumRed^2)^(1/2);
        }
    }
    return;
}
