/*
Faça um programa que gere uma matriz 3x4 e utilize o método de ordenação por troca
para que o conteúdo das colunas seja ordenado de forma crescente
*/

#include <iostream>
#include <time.h>
using namespace std;
int main()
{
    int matriz[3][4];
    int i, j, k;
    srand(time(NULL));
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 4; j++)
        {
            matriz[i][j] = rand() % 100;
            cout << "\t" << matriz[i][j];
        }
        cout << endl;
    }

    int aux;

    for (j = 0; j < 4; j++)
    {
        for (k = 0; k < 2; k++)
        {
            for (i = 0; i < 2; i++)
            {
                if (matriz[i][j] > matriz[i + 1][j])
                {
                    aux = matriz[i][j];
                    matriz[i][j] = matriz[i + 1][j];
                    matriz[i + 1][j] = aux;
                }
            }
        }
    }

    cout << "\n Matriz ordenada \n";

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 4; j++)
        {
            cout << "\t" << matriz[i][j];
        }
        cout << endl;
    }

    return 0;
}