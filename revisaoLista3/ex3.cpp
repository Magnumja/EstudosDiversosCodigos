/*Contar elementos de uma lista: 
Escreva uma função recursiva para 
contar quantos 
elementos existem em uma lista.*/

#include <iostream>


using namespace std;

int lista(int elementos[], int tamanho){
    if (tamanho == 0)
    {
        return 0;
    }
    else
    {
        return 1 + lista(elementos + 1, tamanho - 1);
    }
    
    
}


int main(){
    int tamanho = 5;
    int elementos[tamanho];

    for (int i = 0; i < tamanho; i++)
    {
        cout << "Digite o " << i << "* elemento: ";
        cin >> elementos[i];
    }



    cout << "\n Lista digitada: " << endl;

    for (int i = 0; i < tamanho; i++)
    {
        cout << elementos[i] << " ";
    }

    cout << endl;

    return 0;
    
    
    
    
}