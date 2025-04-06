/*Faça um programa que receba do usuário um arquivo texto e um caractere.
Mostre na tela quantas vezes aquele caractere ocorre dentro do arquivo.*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){
    string NomeArquivo;
    cout << "Digite o nome do arquivo que deseja ler: ";
    getline(cin,NomeArquivo);


    ifstream arquivo(NomeArquivo);

    if (!arquivo)
    {
        cerr << "Erro ao abrir arquivo para leitura. " <<  endl;
        return 1;
    }

    char caractere;

    cout << "Digite o caractere que deseja saber quantas vezes aparece no arquivo: ";
    
}