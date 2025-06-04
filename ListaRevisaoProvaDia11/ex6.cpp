/*
Faça um programa que leia um valor x(quantidade de elementos) e crie dinamicamente
um vetor de x elementos e passe esse vetor para uma função que vai gerar cada elemento
(use a função rand ) desse vetor. No programa principal imprima o vetor gerado pela
função.  Antes de finalizar o programa libere a memória ocupada pelo vetor alocado
dinamicamente.
*/

#include <iostream>
#include <time.h>

using namespace std;

void GerarElementos(int vet[], int tamanho)
{
    srand(time(NULL));
    for (int i = 0; i < tamanho; i++)
    {
        vet[i] = rand() % 100;
    }
}

int main()
{

    int tamanho;
    //int *vet = new int[tamanho];

    int* vet = (int*)malloc(tamanho*sizeof(int));

    cout << "Digite a quantidade de elementos que voce deseja no vetor: ";
    cin >> tamanho;

    GerarElementos(vet, tamanho);

    system("cls");

    cout << "Seu vetor gerado: {";
    for (int i = 0; i < tamanho - 1; i++)
    {
        cout << vet[i] << ", ";
    }
    cout << vet[(tamanho - 1)] << "}";

    //delete[] vet;

    free(vet);
    return 0;
}