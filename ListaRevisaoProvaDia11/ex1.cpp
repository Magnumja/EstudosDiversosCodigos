/*
Faça um programa que gere uma matriz 3x4 e utilize o método de ordenação por troca
(bubble sort) para que o conteúdo das colunas seja ordenado de forma crescente.
*/

/*
 Dicas:
 Para ordenar em ordem crescente, use o operador > (maior) na comparação.
 Se for ordenar por colunas, percorra primeiro as colunas (for externo com j) e depois as linhas (for interno com i).
 Para ordenar por linhas, inverta: percorra primeiro as linhas e depois as colunas.
 Em um bubble sort, sempre compare elementos adjacentes (por isso o loop interno vai até o penúltimo índice).
 O loop de controle da quantidade de passadas (k) é o mesmo número de elementos - 1.
 Exemplo: para 3 elementos, é necessário fazer 2 comparações sucessivas.
*/

#include <iostream>
#include <time.h>
using namespace std;
int main()
{
    int mat[3][4];
    int i, j, k;
    int aux;
    srand(time(NULL));
    cout << "Matriz antes da ordenacao: \n";

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 4; j++)
        {
            mat[i][j] = rand() % 100;
            cout << mat[i][j];
            cout << "\t";
        }
        cout << endl;
    }

    for (j = 0; j < 4; j++)
    {
        for (k = 0; k < 3; k++)
        {
            for (i = 0; i < 2; i++)
            {
                if (mat[i][j] > mat[i + 1][j])
                {
                    aux = mat[i][j];
                    mat[i][j] = mat[i + 1][j];
                    mat[i + 1][j] = aux;
                }
            }
        }
    }

    cout << "\n Matriz depois da ordenacao: \n";

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 4; j++)
        {
            cout << mat[i][j];
            cout << "\t";
        }
        cout << endl;
        
    }

    return 0;
}