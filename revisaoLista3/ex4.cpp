/*Buscar um número em uma lista: 
Implemente uma função recursiva para 
buscar se um 
número está presente em uma lista.*/


#include <iostream>

using namespace std;

int buscarLista(int vetor[], int tamanho, int numero){
    for (int i = 0; i < tamanho; i++)
    {
        if (numero == vetor[i])
        {
            return 1;
        }
    }

    return 0;
    
}
int main(){
    int vetor[]={1,2,3,40,50,60,5,10,30,0,9};
    int tamanho =11;
    int numero;
    cout << "Digite um numero e eu falarei para voce se ele esta na lista: ";
    cin >> numero;

    if (buscarLista(vetor, tamanho, numero))
    {
        cout << "O numero esta na lista, parabens!!";
    }
    else
    {
        cout << "O numero nao esta na lista!";
    }
    
    return 0;

}