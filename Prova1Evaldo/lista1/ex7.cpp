#include <iostream>

using namespace std;

bool verificacaoPrimo(int num)
{
    if (num <=1)
    {
        return 0;
    }
    if (num == 2 || num == 3)
    {
        return 1;
    }
    
    
    for (int i = 2; i < num; i++)
    {

        if (num%i == 0)
        {
            return 0;
        }
        
    }

    return 1;
    
    
}
int main()
{
    int num;
    cout << "Me diga o numero que deseja saber se e primo ou nao: ";
    cin >> num;

    if (!verificacaoPrimo(num))
    {
        cout << "O " << num << " nao e primo" << endl;
    }
    else
    {
        cout << "E primo" << endl;
    }

    return 0;
}