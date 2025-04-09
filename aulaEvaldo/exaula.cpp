#include <fstream>
#include <iostream>
using namespace std;
void soma(int a, int b, int &r)
{
    r = a + b;
}

int main()
{
    int x = 10;
    int y = 20;
    int z;

    soma (x,y,z);

    cout << "Soma: " << z << endl;
    
    return 0;
}
