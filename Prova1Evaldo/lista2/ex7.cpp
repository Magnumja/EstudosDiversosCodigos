/*Faça um programa que receba do usuário um arquivo texto. Crie outro arquivo
texto contendo o texto do arquivo de entrada, mas com as vogais substituídas por*/ 

#include <iostream>
#include <fstream>
#include <string>

using namespace std;


int main(){

    string nomeArquivo;
    cout << "Me de o nome do arquivo que deseja que leia: ";
    getline(cin, nomeArquivo);

    ifstream arquivo(nomeArquivo);

    if (!arquivo)
    {
        cerr << "Erro ao abrir arquivo.";
        return 1;
    }
    
    char caractereLido;

    while (arquivo.get(caractereLido))
    {
        if (caractereLido == 'a' || caractereLido == 'e' || caractereLido == 'i' || caractereLido == 'o' || caractereLido == 'u')
        {
             caractereLido = '*';
        }
            
        cout << caractereLido;
    }

    return 0;
    
    
}