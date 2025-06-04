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

void bubble(int vet[], int k)
{
    for (int k = 0; k < k - 1; k++)
    {
        for (int i = 0; i < k - 1 - k; i++)
        {
            if (vet[i] > vet[i + 1])
            {
                int aux = vet[i];
                vet[i] = vet[i + 1];
                vet[i + 1] = aux;
            }
        }
    }
}

void insertion(int vet[], int k)
{
    for (int i = 1; i < k; i++)
    {
        int aux = vet[i];
        for (int k = i - 1; k >= 0; k--)
        {
            if (vet[k] > aux)
            {
                vet[k + 1] = vet[k];
            }
            else
            {
                break;
            }
        }
        vet[k + 1] = aux;
    }
}

void selection(int vet[], int k)
{
    bool troca;

    for (int i = 0; i < k - 1; i++)
    {
        int menor = vet[i];
        int posicao = i;
        troca = false;

        for (int k = i + 1; k < 9; k++)
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
    int i, k, op;

    k = 10;

    srand(time(NULL));

    for (int i = 0; i < 10; i++)
    {
        vet[i] = 0;
    }

    do
    {
        cout << "O que deseja ver: \n";
        cout << "1- vetor aleatorio\n";
        cout << "2- Vetor insertion\n";
        cout << "3- Vetor bubble\n";
        cout << "4- Vetor selection\n";
        cout << "5- Sair\n";
        cout << "Escolha: ";

        cin >> op;

        int vetor_copia[10];
        for (int i = 0; i < 10; i++)
        {
            vetor_copia[i] = vet[i];
        }

        switch (op)
        {
        case 1:
            for (int i = 0; i < 10; i++)
            {
                vet[i] = rand() % 100;
            }
            cout << "Vetor gerado: {";
            for (int i = 0; i < 9; i++)
            {
                cout << vet[i] << ", ";
            }
            cout << vet[9] << "}";
            cout << endl;
            break;
        case 2:
            bool vetorEstaVazioOuZero_2 = true;
            for (int i = 0; i < 10; i++)
            {
                if (vet[i] != 0)
                {
                    vetorEstaVazioOuZero_2 = false;
                    break;
                }
            }
            if (vetorEstaVazioOuZero_2)
            {
                cout << "Por favor, gere o vetor primeiro (Opcao 1) ou o vetor gerado so contem zeros." << endl;
            }
            else
            {
                insertion(vetor_copia, k);
                cout << "\n Vetor Insertion: {";
                for (int i = 0; i < 9; i++)
                {
                    cout << vetor_copia[i] << ", ";
                }
                cout << vetor_copia[9] << "}";
                cout << endl;
            }
            break;
        case 3:
            bool vetorEstaVazioOuZero_3 = true;
            for (int i = 0; i < 10; i++)
            {
                if (vet[i] != 0)
                {
                    vetorEstaVazioOuZero_3 = false;
                    break;
                }
            }
            if (vetorEstaVazioOuZero_3)
            {
                cout << "Por favor, gere o vetor primeiro (Opcao 1) ou o vetor gerado so contem zeros." << endl;
            }
            else
            {
                bubble(vetor_copia, k);
                cout << "\n Vetor Bubble: {";
                for (int i = 0; i < 9; i++)
                {
                    cout << vetor_copia[i] << ", ";
                }
                cout << vetor_copia[9] << "}";
                cout << endl;
            }
            break;
        case 4:
            bool vetorEstaVazioOuZero_4 = true;
            for (int i = 0; i < 10; i++)
            {
                if (vet[i] != 0)
                {
                    vetorEstaVazioOuZero_4 = false;
                    break;
                }
            }
            if (vetorEstaVazioOuZero_4)
            {
                cout << "Por favor, gere o vetor primeiro (Opcao 1) ou o vetor gerado so contem zeros." << endl;
            }
            else
            {
                selection(vetor_copia, k);
                cout << "\n Vetor Selection: {";
                for (int i = 0; i < 9; i++)
                {
                    cout << vetor_copia[i] << ", ";
                }
                cout << vetor_copia[9] << "}";
                cout << endl;
            }
            break;
        case 5:
            cout << "Saindo do programa. Ate mais!\n";
            break;
        default:
            cout << "Opcao invalida. Por favor, escolha um numero entre 1 e 5.\n";
            break;
        }
    } while (op != 5);

    return 0;
}