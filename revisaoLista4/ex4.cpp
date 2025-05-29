/*Escrever um programa para gerar uma matriz de 4 x 5 números reais, multiplicar a primeira
coluna por qualquer outra da matriz e mostrar a soma dos produtos. O programa deve ser
decomposto em subprogramas e utilizar ponteiros para acessar os elementos da matriz*/

#include <iostream>
#include <time.h>

using namespace std;

int main()
{
    float mat[4][5];
    int i, j;
    float soma = 0;

    srand(time(NULL));

    cout << "MATRIZ: \n";

    for (i = 0; i < 4; i++)
    {

        for (j = 0; j < 5; j++)
        {
            mat[i][j] = rand() % 100;
            cout << "\t" << mat[i][j];
        }
        cout << endl;
    }

    int coluna_aleatoria = rand() % 4 + 1;

    for (i = 0; i < 4; i++)
    {
        float *p1 = &mat[i][0];
        float *p2 = &mat[i][coluna_aleatoria];
        soma += (*p1) * (*p2);
    }

    cout << "A soma dos produtos foi: " << soma << endl;

    return 0;
}