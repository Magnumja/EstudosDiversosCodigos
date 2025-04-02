/*Implemente um programa que tenha uma função para verificar se um número é primo.
A função deve retornar verdadeiro se o número for primo e falso caso contrário.
*/

#include <iostream>


using namespace std;

bool ValidarPrimo(int num)
{
    if (num < 2)
        return 0;

    for (int i = 2; i < num; i++)
    {
        if (num % i == 0)
            return 0;
    }
    return true;
}

int main()
{
    int num;
    
 
    cout << L"Me fale qual o numero que deseja saber se é primo: ";
    cin >> num;

    if (ValidarPrimo(num))
    {
        cout << num << "É um numero primo. " << endl;
    }
    else
    {
        cout << num << "Nao é um numero primo" << endl;
    }
    return 0;
}