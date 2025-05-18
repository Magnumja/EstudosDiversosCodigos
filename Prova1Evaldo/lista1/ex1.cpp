#include <iostream>

using namespace std;

bool ValidarNota(int nota)
{
    return (nota >= 0 && nota <= 10);
}

int main()
{
    int nota;
    do
    {

        cout << "Me fale qual o valor de sua nota: ";
        cin >> nota;

        if (ValidarNota(nota))
        {
            cout << "Sua nota foi aceita! muito oobrigado" << endl;
        }
        else
        {
            cout << "Tente novamente, a nota nao foi aceita! \n";
        }

    } while (!ValidarNota(nota));

    return 0;
}