/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
using namespace std;
void somar (int a, int b, int *r)
{
    *r=a+b;
}

int main()
{
    int x,y,z;
    int *p;
    x=10;
    y=20;
    p=&z;
    cout<<"Soma: "<<z<<endl;
    somar(x,y,p);
    cout<<"Soma: "<<*p;
    return 0;
}