/*) Faça um programa que gere uma matriz 3x4 e utilize o método de ordenação por
troca para que o conteúdo das colunas seja ordenado de forma crescente.
*/

#include <iostream>
#include <time.h>

using namespace std;

int main(){

    int mat[3][4];
    int i, j, k;
    int aux;

    srand(time(NULL));
    for ( i = 0; i < 3; i++)
    {
        for ( j = 0; j < 4; j++)
        {
            mat[i][j] = rand()%100;
        }
        
    }
    
    cout << "Matriz antes da ordenacao: \n";

    for ( i = 0; i < 3; i++)
    {
        for ( j = 0; j < 4; j++)
        {
            cout << mat[i][j];
            cout << "\t";
        }
        cout << endl;
    }

    cout << "Matriz apos a ordenacao: \n";

    for (i = 0; i < 3; i++)
    {
        for ( k = 0; k < 3; k++)
        {
            for (j = 0; j < 3; j++)
            {
                if (mat[i][j] > mat[i][j+1])
                {
                    aux = mat[i][j];
                    mat[i][j] = mat[i][j+1];
                    mat[i][j+1] = aux;
                }
                
            }
            
        }
        
    }

    for ( i = 0; i < 3; i++)
    {
        for ( j = 0; j < 4; j++)
        {
            cout << mat[i][j];
            cout << "\t";
        }
        cout << endl;
    }
    




    return 0;
}