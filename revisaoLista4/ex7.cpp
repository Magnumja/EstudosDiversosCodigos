/*
É necessário armazenar a seguinte informação de uma pessoa: nome, idade, altura 
e  peso.  Escrever  uma  função  que  leia  os  dados  de  uma  pessoa,  recebendo  como 
parâmetro um ponteiro e outra função que os visualize
*/


#include <iostream>

using namespace std;

struct Informacoes
{
    string nome;
    int idade;
    float altura, peso;
};

void leitura(Informacoes* p){

    cout << "Me diga qual seu nome: ";
    cin >> p->nome;
    cout << "Idade: ";
    cin >> p->idade;
    cout<< "Altura: ";
    cin >> p->altura;
    cout << "Peso: ";
    cin >> p->peso;

}


void visualizacao(Informacoes* p){
    cout << "Nome: " << p->nome;
    cout << "\nIdade: " << p->idade;
    cout << "\nAltura: " << p->altura;
    cout << "Peso: " << p->peso;

}


int main(){

    Informacoes pessoa;
    Informacoes* p;

    p = &pessoa;

    leitura(p);

    system("cls");
    
    visualizacao(p);

    return 0;
}