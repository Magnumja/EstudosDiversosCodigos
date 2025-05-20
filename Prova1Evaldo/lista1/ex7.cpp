#include <iostream>

using namespace std;

int verificacaoNaoPrimo(int num, int div1, int div2)
{
    return (num != 1 && (div1 == 0 || div2 == 0));
}
int main()
{
    int num;
    int div1, div2;
    cout << "Me diga o numero que deseja saber se e primo ou nao: ";
    cin >> num;

    div1 = num % 2;
    div2 = num % 3;

    if (verificacaoNaoPrimo(num, div1, div2))
    {
        cout << "O " << num << " nao e primo";
    }
    else
    {
        cout << "E primo";
    }

    return 0;
}