/*Faça um programa que tenha uma sub-rotina que receba dois números inteiros.
A sub-rotina deve calcular e exibir a soma dos dois números, além da subtração e da divisão do maior pelo menor.
Certifique-se de que os números informados não sejam iguais.*/

#include <iostream>

using namespace std;

bool verificarnumero(int num1, int num2)
{
    return (num1 != num2);
}

int main()
{
    int num1, num2, soma, subtracao, divisao;
    int escolha;

    do
    {
        cout << "Qual os numeros escolhidos?  \n";
        cin >> num1 >> num2;

        if (!verificarnumero(num1, num2))
        {
            cout << "Numeros invalidos, nao podem ser iguais! \n";
            continue;
        }

        cout << "\nO que voce deseja fazer?\n";
        cout << "1- Soma\n";
        cout << "2- Subtracao\n";
        cout << "3- divisao\n";
        cout << "4- Sair\n";

        cin >> escolha;
        system("cls");

        switch (escolha)
        {
        case 1:

            soma = num1 + num2;
            cout << "A soma vale: " << soma << endl;

            break;

        case 2:

            subtracao = abs(num1 - num2);
            cout << "A subtracao vale: " << subtracao << endl;
            break;

            break;

        case 3:

            divisao = float (num1 / num2);
            cout << "A divisao vale: " << divisao << endl;
            break;

        case 4:
            cout << "Foi um prazer te servir!";
            return 0;

            break;
        default:
            cout << "Opcao invalida, tente novamente!" << endl;

            break;
        }

    } while (1);
}