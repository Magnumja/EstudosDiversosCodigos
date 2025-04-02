/*Escreva um programa que tenha uma função para calcular o
fatorial de um número inteiro informado pelo usuário.
*/

#include <iostream>

using namespace std;

void calculoFatorial(int num, int &fatorial)
{
    fatorial = 1;
    
    for (int i = num; i > 0; i--)
    {
        fatorial *= i;

    }
}

int main()
{
    int num, fatorial;

    cout << "Digite qual numero deseja calcular o fatorial: ";
    cin >> num;

    calculoFatorial(num, fatorial);

    cout << "O valor do fatorial é: " << fatorial << endl;

    return 0;
}