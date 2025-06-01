/*
Desenvolva um programa que crie um registro Pessoa com nome(string/vetor de 
caracteres) e cpf (inteiro).
a) Use new() para alocar dinamicamente uma variável para cadastrar uma 
pessoa.
b) Leia e exiba os dados desta pessoa.
c) Após o uso libere a memória por meio do operador delete()
*/

#include <iostream>

using namespace std; 

int main(){

    char* nome = new char[50];
    long long int* cpf = new long long int;

    cout << "Me diga o seu nome completo por favor: ";
    cin.getline(nome, 50);

    cout << "E seu CPF(sem pontos, apenas numeros): ";
    cin >> *cpf;



    cout << "Voce, " << nome << ", do CPF: " << *cpf << " esta registrado! " << endl;

    delete[] nome;
    delete cpf;


    return 0;
}
