/*Contar elementos de uma lista: Escreva uma função
recursiva para contar quantos elementos existem em uma lista.*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int lista()
{
    int n;
    cin >> n;
    if (n == -1)
        return 0;
    return 1 + lista();
}

int main()
{

    cout << "Digite os numeros de sua lista e falarei quantos elementos possui: (digite -1 para parar)  ";
    int resultado = lista();

    cout << "Possui " << resultado << " elementos." << endl;

    return 0;
}