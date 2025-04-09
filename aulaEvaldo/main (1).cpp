/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
using namespace std;
void somar (int a, int b, int &r)
{
    r=a+b;
}

int main()
{
    int x,y,z;
    x=10;
    y=20;
    z=-1;
    somar(x,y,z);
    cout<<"Soma: "<<z;
    return 0;
}