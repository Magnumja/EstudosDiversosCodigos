/*1- Faça um programa que gere uma matriz 3x4 e utilize o método de ordenação
por troca para que o conteúdo das colunas seja ordenado de forma crescente.*/

#include <iostream>
#include <cstddef>
#include <time.h>

using namespace std;

int main()
{
    int mat[3][4];
    int i, j;
    int k;

    srand(time(NULL));
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 4; j++)
        {
            mat[i][j] = rand() % 100;
            cout << "\t" << mat[i][j];
        }d
        cout << endl;
    }
    int aux;
    /*for (j = 0; j < 4; j++) 
    {
        for (i = 0; i < 2; i++) 
        {
            for (int k = 0; k < 2; k++)
            {
                if (mat[k][j] > mat[k + 1][j])
                {
                    int aux = mat[k][j];
                    mat[k][j] = mat[k + 1][j];
                    mat[k + 1][j] = aux;
                }
            }
        }
    }*/



    for (k = 0; k < 3; k++) 
    {
        for (i = 0; i < 3; i++) 
        {
            for (int j = 0; j < 4; j++)
            {
                if (mat[i][j] > mat[i + 1][j])
                {
                    int aux = mat[i][j];
                    mat[i][j] = mat[i + 1][j];
                    mat[i + 1][j] = aux;
                }
            }
        }
    }

    cout << "\nMatriz com colunas ordenadas:\n";
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << mat[i][j] << "\t";
        }
        cout << endl;
    }

    return 0;
}