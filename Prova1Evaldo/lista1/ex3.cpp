#include <iostream>

using namespace std;

bool validarNumero(float num1, float num2)
{
    return (num1 != num2);
}

int main()
{
    float num1, num2, div, sub, soma;

    do
    {
        cout << "Me fale os dois numeros que deseja saber a soma, subtracao e divisao: ";
        cin >> num1 >> num2;
        cout << "\n";

        if (validarNumero(num1, num2))
        {
            soma = num1 + num2;
            sub = num1 - num2;
            if (num1 == 0 || num2 == 0)
            {
                cout << "A divisao por zero nao eh permitida pois nao existe \n";
                cout << "O valor da soma e " << soma << " e o valor da subtracao e " << sub << endl;
            }
            else if (num1 > num2)
            {
                div = num1 / num2;
                cout << "O valor da divisao e " << div;
                cout << "O valor da soma e " << soma << " e o valor da subtracao e " << sub << endl;
            }
            else
            {
                div = num2 / num1;
                cout << "O valor da divisao e " << div;
                cout << "O valor da soma e " << soma << " e o valor da subtracao e " << sub << endl;
            }
        }
        else
        {
            cout << "Num 1 e num 2 nao podem ser iguais, tente novamente! \n";
        }

    } while (!validarNumero(num1, num2));
    return 0;
}