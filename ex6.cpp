/*
Faça um programa em C++ que:
a. Crie um vetor de inteiros com 50 posições.
b. Utilizando a função rand() e limitando os valores até 99 preencha todas as
posições.
c. Ordene o vetor seguindo o algoritmo apresentado em pseudocódigo.
TAM ← 5 //EXEMPLO DE UM VETOR COM 5 POSIÇÕES
PARA i DE 1 ATÉ TAM FAÇA
j ← i
AUX ← A[ i ]
ENQUANTO ( j &gt; 1 E AUX &lt; A [ j - 1 ])
A[ j ] ← A[ j - 1]
j- -
FIM ENQUANTO
A[j] ← AUX
FIM PARA
d. Apresente na tela o vetor ordenado.
e. Gravar em um arquivo “ordenado.txt” o vetor resultante da ordenação.

*/
#include <time.h>
#include <iostream>

using namespace std;

int main()
{
    int vet[50];
    srand(time(NULL));
    for (int i = 0; i < 50; i++)
    {
        vet[i] = rand() % 100;
    }

    int tam = 50;
    for (int i = 0; i < tam; i++)
    {
        int j = i;
        int aux = vet[i];
        while (j > 0 && aux < vet[j - 1])
        {
            vet[j] = vet[j - 1];
            j--;
        }
        vet[j] = aux;
    }

    cout << "Vetor ordenado: ";
    for (int i = 0; i < tam; i++)
    {
        cout << vet[i] << "|";
    }

    FILE *arquivo = fopen("ordenado.txt", "w");
    if (arquivo == NULL)
    {
        cout << "Erro ao abrir arquivo" << endl;
        return 1;
    }
    fprintf(arquivo, "\nVetor ordenado");
    cout << "Vetor ordenado: ";
    for (int i = 0; i < tam; i++)
    {
        cout << vet[i] << "|";
    }
    fclose(arquivo);

    return 0;
}