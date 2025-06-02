#include <iostream>

using namespace std;

int main()
{
    double Notas[10];
    int posicao;
    double menor, aux;
    bool troca;

    // Entrada de notas
    for (int i = 0; i < 10; i++)
    {
        cout << "Digite a " << i + 1 << "ª nota: ";
        cin >> Notas[i];
    }

    system("cls"); 

    // Algoritmo de ordenação por seleção (Selection Sort)
    for (int j = 0; j < 9; j++) // percorre até o penúltimo elemento, pois o ultimo ja esta no lugar certo
    {
        menor = Notas[j]; // assume que o menor está na posição atual
        posicao = j;
        troca = false;

        for (int k = j + 1; k < 10; k++) // procura um valor menor nos elementos seguintes, que ao final ele vai achar
        {                                // o valor definitivo de menor por agora, fazendo com que ele vai para o if de troca
            if (Notas[k] < menor)
            {
                menor = Notas[k];
                posicao = k;
                troca = true;
            }
        }

        if (troca) // se achou um valor menor, faz a troca
        {
            aux = Notas[j];
            Notas[j] = menor;
            Notas[posicao] = aux;
        }
    }

    // Exibe as notas ordenadas
    for (int m = 0; m < 10; m++)
    {
        cout << " | " << Notas[m];
    }

    return 0;
}
