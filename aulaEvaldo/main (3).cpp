/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
using namespace std;
void dec2bin(int num);
int main()
{
    int num=15;
    dec2bin(num);
    return 0;
}

void dec2bin(int num){
    if(num<2)
    {
        cout<<num<<" ";
        return;
    }
    dec2bin(num/2);
    cout<<num%2<<" ";
}




