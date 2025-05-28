/*Crie um programa que declare um vetor de inteiros com 5 posições e utilizando um 
ponteiro faça:
a) Preencha o vetor.
b) Mostre os dados armazenados.
c) Calcule a média dos dados armazenado*/


#include <iostream>
using namespace std;

int main(){
    int *p;
    int vetor[5];

    p=vetor; // ou  p=&vetor[0] vai receber o endereco de memoria do primeiro elemento do vetor(array)

    cout << "\n" << p << "\n";







    return 0;
}