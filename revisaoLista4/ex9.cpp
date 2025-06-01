/*
Desenvolva um programa que :
a) Peça ao usuário quantos números deseja armazenar.
b) Aloque dinamicamente por meio do operador new().
c) Preencha toda a estrutura.
d) Apresente o maior valor armazenado.
e) Após o uso libere a memória por meio do operador delete()
*/

#include <iostream>

using namespace std;

int main()
{

    int quantidade;

    cout << "Me fale quantos numeros deseja armazenas: ";
    cin >> quantidade;

    system("cls");

    int *numeros = new int[quantidade];

    for (int i = 0; i < quantidade; i++)
    {
        cout << "Me fale o " << i + 1 << " que deseja armazenar: ";
        cin >> numeros[i];
    }

    int maior;
    maior = numeros[0];

    for (int i = 0; i < quantidade; i++)
    {

        if (numeros[i] > maior)
        {
            maior = numeros[i];
        }
    }

    cout << "\n" << "O maior valor armazenado foi " << maior << endl;

    delete[] numeros;

    return 0;
}