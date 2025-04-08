/* Sequência de Fibonacci: Escreva uma função recursiva para calcular
 o enésimo número de Fibonacci (Fn = Fn-1 + Fn-2).
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int fibonacci(int n)
{
    if (n == 0)
    {
        return 0;
    }
    else if (n == 1)
    {
        return 1;
        ;
    }
    else
    {
        return (fibonacci(n - 1) + fibonacci(n - 2));
    }
}

int main()
{
    int n;
    cout << "Fale o numero que deseja  da sequencia de fibonacci: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int resultado = fibonacci(i);
        cout << "  " << resultado;
    }

    return 0;
}