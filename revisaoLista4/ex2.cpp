/*  Crie um programa que leia um número inteiro e imprima:
a) O valor digitado.
b) O endereço da memória.
c) O conteúdo da memória apontado pelo ponteiro*/

#include <iostream>
#include <cstddef>
using namespace std;

int main(){
    int var1;

    cout << "Digite o valor da variavel 1: ";
    cin >> var1;

    int *pont = &var1;

    cout << "Valor da variavel digitada: " << var1;
    cout << "\n" << "O endereco da memoria: " << &var1;
    cout << "\n" << "O conteudo da memoria apontado pelo ponteiro: " << *pont << endl;

    return 0;
}