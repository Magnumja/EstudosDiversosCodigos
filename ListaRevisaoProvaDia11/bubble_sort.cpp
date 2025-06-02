/*
Aqui comecei a aprender bubble sort e farei um exemplo.
colocarei 10 notas de alunos e quero saber do menor ao maior.
*/

#include <iostream>

using namespace std;

int main()
{
    double Notas[10];
    double aux;

    for (int i = 0; i < 10; i++)
    {
        cout << "Digite a " << i + 1 << " nota:";
        cin >> Notas[i];
    }

    for (int k = 0; k < 10; k++)
    {
        for (int l = 0; l < 9; l++)
        {
            if (Notas[l] > Notas[l + 1])
            {
                aux = Notas[l];
                Notas[l] = Notas[l+1];
                Notas[l + 1]=aux;
            }
        }
    }

    for (int m = 0; m < 10; m++)
    {
        cout << Notas[m] << " | ";
    }

    return 0;
}