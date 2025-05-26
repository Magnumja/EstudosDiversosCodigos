/*Fatorial de um número: Crie uma função recursiva para calcular o fatorial de um número 
n (n! = n * (n-1) * (n-2) * ... *1)*/

#include <iostream>

using namespace std;

int fatorial(int n){
    if (n == 0)
    {
        return 1;
    }
    else
    {
        return n*fatorial(n-1);
    }
    
}

int main(){
    int numero;

    cout << "Me fale o numero que deseja saber o fatorial: ";
    cin >> numero;

    int resultado = fatorial(numero);

    cout << "Fatorial de " << numero << " vale " << resultado << endl;

    return 0;
}