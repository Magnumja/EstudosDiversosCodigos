/*
Escrever um programa que leia um número determinado de inteiros (1.000 como máximo)
do terminal e os visualize na mesma ordem e com a condição de que se escreva somente
uma vez cada inteiro. Se o inteiro já foi impresso, não deve ser visualizado novamente. Por
exemplo, se os números seguintes são lidos do terminal 55, 78,25, 55, 24,3 e 7 o  programa
deve visualizar o seguinte: 55,78,25,24,3 e 7. Deve-se trabalhar com ponteiros para tratar
com o array no qual foram armazenados os números.
*/

#include <iostream>

using namespace std;

int main()
{

    int *Numeros = new int[1000];
    int i = 1;
    int *pont = &i;
    int k = 0;
    int *pont2 = &k;

    while (1)
    {
        cout << "Digite o " << i << " numero que deseja armazenar: ";
        (*pont)++;
        cin >> Numeros[k];
        if (Numeros[k] == -1)
        {
            break;
        }
        k++;
    }

    int tamanho = k;

    system("cls");

    *pont2 = 0;

    cout << "Numeros digitados: \n";

    for (int j = 0; j < tamanho; j++)
    {
        bool repetido = false;
        for (int l = 0; l < j; l++)
        {
            if (Numeros[l] == Numeros[j])
            {
                repetido = true;
                break;
            }
        }

        if (!repetido)
        {
            cout << Numeros[j] << ", ";
        }
    }

    delete[] Numeros;
    return 0;
}