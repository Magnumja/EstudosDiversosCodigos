/*1. Fatorial de um número: Crie uma função recursiva para calcular o fatorial de um número n (n! = n * (n-1) * (n-2) * … *1).
 */

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int fatorial(int n)
{

    if (n == 0)
    {
        return 1;
    }
    else
    {
        return (n * fatorial(n - 1));
    }
}

int main()
{
    int n;
    cout << "Digite o numero que deeseja saber o fatorial: ";
    cin >> n;
    fatorial(n);

    int resultado = fatorial(n);
    cout << "O valor da fatorial do numero " << n << " vale " << resultado << endl;

    return 0;
}