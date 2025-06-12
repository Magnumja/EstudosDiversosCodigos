/*1- Gerar um vetor de inteiros com 10 posições.
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

void gerar(int v[])
{
    for (int i = 0; i < 10; i++)
    {
        v[i] = rand() % 100;
        cout << v[i] << "|";
    }
    cout << "\n";
}

void inserction(int v[])
{
    for (int i = 0; i < 9; i++)
    {
        for (int k = i + 1; k > 0; k--)
        {
            if (v[k] < v[k - 1])
            {
                int aux = v[k];
                v[k] = v[k - 1];
                v[k - 1] = aux;
            }
            else
                break;
        }
    }
    cout << "\n";
    for (int i = 0; i < 10; i++)
    {
        cout << v[i] << "|";
    }
    cout << "\n";
}

void bubble(int v[])
{
    for (int i = 0; i < 9; i++)
    {
        for (int k = i + 1; k < 10; k++)
        {
            if (v[i] > v[k])
            {
                int aux = v[i];
                v[i] = v[k];
                v[k] = aux;
            }
        }
    }
    cout << "\n";
    for (int i = 0; i < 10; i++)
    {
        cout << v[i] << "|";
    }
    cout << "\n";
}

void selection(int v[])
{
    for (int i = 0; i < 9; i++)
    {
        int posicao = i; 
        for (int k = i + 1; k < 10; k++)
        {
            if (v[k] < v[posicao])
            {
                posicao = k;
            }
        }
       
        if (posicao != i)
        {
            int aux = v[i];
            v[i] = v[posicao];
            v[posicao] = aux;
        }
    }

    cout << "\n";
    for (int i = 0; i < 10; i++)
    {
        cout << v[i] << "|";
    }
    cout << "\n";
}

int main()
{
    int v[10];
    int op;
    srand(time(NULL));

    do
    {
        cout << "O que deseja fazer? \n";
        cout << "1-Vetor Gerado\n";
        cout << "2-Ordenar por insercao\n";
        cout << "3-Ordenar por Bubble\n";
        cout << "4-Ordenar por Selection\n";
        cout << "5-Sair\n";
        cout << "Escolhe: ";
        cin >> op;

        switch (op)
        {
        case 1:
            system("cls");

            cout << "O vetor gerado foi: ";
            gerar(v);
            break;
        case 2:
            system("cls");
            cout << "O vetor ordenado foi: ";
            inserction(v);
            break;
        case 3:
            system("cls");
            cout << "O vetor ordenado foi ";
            bubble(v);

            break;
        case 4:
            system("cls");
            cout << "O vetor ordenado foi ";
            selection(v);
            break;
        case 5:
            break;
        default:
            break;
        }
    } while (op != 5);

    return 0;
}