/*
3- Utilizando o código desenvolvido na questão 4 armazenar o vetor inicial em uma linha do
arquivo e o vetor ordenado em outra linha do arquivo. Utilize um arquivo no formato txt.
4- O trecho de código a seguir apresenta alguns comandos referentes a alocação dinâmica
de memória. Descreva o que o seguinte trecho do código faz.
int *x;
x = malloc (10 * sizeof (int))
*/

#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

int main()
{
    int *x;
    x = (int *)malloc(10 * sizeof(int));

    for (int i = 0; i < 10; i++)
    {
        x[i] = rand() % 100;
    }

    FILE *arquivo = fopen("vetores.txt", "w");
    if (arquivo == NULL)
    {
        cout << "Erro ao abrir o arquivo." << endl;
        return 1;
    }

    fprintf(arquivo, "Vetor antes de ordenacao: ");
    for (int i = 0; i < 9; i++)
    {
        fprintf(arquivo, "%d ", x[i]);
    }
    fprintf(arquivo,"%d",x[9]);

    fprintf(arquivo, "\nVetor depois da ordenacao: ");
    for (int i = 0; i < 9; i++)
    {
        for (int k =i+1; k < 10; k++)
        {
            if (x[k] < x[i])
            {
                int aux = x[k];
                x[k] = x[i];
                x[i] = aux;
            }
            
        }
        
    }
    for (int i = 0; i < 9; i++)
    {
        fprintf(arquivo, "%d ", x[i]);
    }
    fprintf(arquivo,"%d",x[9]);

    
    fclose(arquivo);
    free(x);
    return 0;
}