#include <iostream>

using namespace std;

int main()
{
    double Notas[10];
    double aux;

    for (int i = 0; i < 10; i++)
    {
        cout << "Digite a " << i + 1 << " nota: ";
        cin >> Notas[i];
    }

    system("cls");

    for (int j = 0; j < 9; j++)
    {
        for (int k = j + 1; k > 0; k--)
        {

            if (Notas[k] < Notas[k - 1])
            {
                aux = Notas[k];
                Notas[k] = Notas[k - 1];
                Notas[k - 1] = aux;
            }
            else
                break;
        }
    }

    for (int m = 0; m < 10; m++)
    {
        cout << " | " << Notas[m];
    }

    return 0;
}