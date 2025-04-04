/*Faça um programa que receba do usuário um arquivo texto e mostre na tela
quantas linhas esse arquivo possui.*/


#include <iostream>
#include <fstream>
#include <string>


using namespace std;

int main()
{
    string nomeArquivo;
    cout << "Digite o nome do arquivo: ";
    cin >> nomeArquivo;

    ifstream arquivo(nomeArquivo);

    if (!arquivo)
    {
       cerr << "Erro ao abrir o arquivo" << endl;
       return 1;
    }

    int contadorLinhas = 0;
    string linha;

    while (getline(arquivo, linha)){
        contadorLinhas++;
    }

    arquivo.close();

    cout << "O arquivo possui : " << contadorLinhas << endl;

    return 0;
    
}