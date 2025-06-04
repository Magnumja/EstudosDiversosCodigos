/*
Faça um programa que apresente o seguinte menu:
1- Gerar um vetor de inteiros com 10 posições.
2- Ordenar por Inserção.
3- Ordenar pelo método da Bolha.
4- Ordenar por Seleção.
5- Sair.
● O vetor deve ser gerado utilizando uma função para definir seu conteúdo
aleatoriamente.
● Após a geração do vetor os valores devem ser apresentados.
● Após a ordenação os valores do vetor devem ser apresentados.
● A execução dos itens 2, 3 e 4 do menu devem ser feitas por meio de funções e
devem ser passados como parâmetros a variável vetor e o seu tamanho.
*/

#include <iostream>
#include <time.h>
using namespace std;

void Insercao(int vet[], int tamanho)
{
    for (int i = 0; i < tamanho - 1; i++)
    {
        for (int k = i + 1; k > 0; k--)
        {
            if (vet[i] > vet[k])
            {
                int aux = vet[i];
                vet[i] = vet[k];
                vet[k] = aux;
            }
            else
                break;
        }
    }
}

void Bubble(int vet[], int tamanho)
{
    for (int i = 0; i < tamanho; i++)
    {
        for (int k = i + 1; k < tamanho - 1; k++)
        {
            if (vet[i] > vet[k])
            {
                int aux = vet[i];
                vet[i] = vet[k];
                vet[k] = aux;
            }
        }
    }
}

void Selection(int vet[], int tamanho)
{
    for (int i = 0; i < tamanho; i++)
    {
        int menor = vet[i];
        int posicao = i;
        bool troca;
        troca = false;

        for (int k = i + 1; k < tamanho; k++)
        {
             if (vet[k] < menor)
            {
                menor = vet[k];
                posicao = k;
                troca = true;
            }
        }

        if (troca)
        {
            int aux = vet[i];
            vet[i] = menor;
            vet[posicao] = aux;
        }
        
    }
}

int main()
{
    int vet[10];
    int tamanho = 10;
    bool troca;
    int i, op, aux, k;

    srand(time(NULL));
    for (i = 0; i < 10; i++)
    {
        vet[i] = rand() % 100;
    }

    cout << "Por favor, escolha uma das opcoes abaixo: \n";
    cout << "1- Gerar vetor de inteiro com 10 posicoes.\n";
    cout << "2- Vetor ordenado por Insercao. \n";
    cout << "3- Vetor Ordenado por Bubble \n";
    cout << "4- Ordenar por selecao. \n";
    cout << "5- SAIR. \n";
    cout << "Escolha: ";
    cin >> op;

    switch (op)
    {
    case 1:
        cout << "O vetor gerado foi: {";
        for (i = 0; i < 9; i++)
        {
            cout << vet[i] << ", ";
        }
        cout << vet[9] << "}";
        break;
    case 2:
        cout << "Vetor ordenado por Insercao: {";
        Insercao(vet, tamanho);
        for (i = 0; i < 9; i++)
        {
            cout << vet[i] << ", ";
        }
        cout << vet[9] << "}";
        break;
    case 3:
        cout << "Vetor ordenado por bubble: {";
        Bubble(vet, tamanho);
        for (i = 0; i < 9; i++)
        {
            cout << vet[i] << ", ";
        }
        cout << vet[9] << "}";
        break;
    case 4:
        cout << "Vetor ordenado por Selection: {";
        Selection(vet, tamanho);
        for (i = 0; i < 9; i++)
        {
            cout << vet[i] << ", ";
        }
        cout << vet[9] << "}";
    case 5:
        if (op == 5)
        {
            break;
        }

    default:
        break;
    }

    return 0;
}
