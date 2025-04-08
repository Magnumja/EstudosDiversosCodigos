/*Soma de uma lista: Crie uma função recursiva para 
somar todos os elementos de uma lista de números.*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int lista(int n){
    cin >> n;
    if (n == -1)
    {
        return 0;
    } else
    {
        return (n + lista(n));
    }
    
}


int main(){
    int n;
    int resultado;
    cout << "Me fale os numeros da sua lista:  (digite -1 para parar) ";

    resultado = lista(n);
    cout << "O valor da soma dos numeros da sua lista vale: " << resultado << endl;

    return 0;


    
}