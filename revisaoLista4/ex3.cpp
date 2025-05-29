/*Crie um programa que declare um vetor de inteiros com 5 posições e utilizando um
ponteiro faça:
a) Preencha o vetor.
b) Mostre os dados armazenados.
c) Calcule a média dos dados armazenado*/

#include <iostream>
using namespace std;

int main()

{
    // criar por alocacao dinamica
    int vetor[5] = new int;
    int *p = vetor; 
    int soma = 0;

    
    for (int i = 0; i < 5; i++)
    {
        *(p + i) = (i + 1) * 10; 
    }

    
    cout << "Valores armazenados: ";
    for (int i = 0; i < 5; i++)
    {
        cout << *(p + i) << " ";
        soma += *(p + i);
    }

    float media = soma / 5.0;
    cout << "\nA media dos valores do vetor vale: " << media << endl;

    delete[];

    return 0;
}
