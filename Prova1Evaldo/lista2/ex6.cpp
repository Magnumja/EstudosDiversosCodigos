/*Faça um programa que receba do usuário um arquivo texto e mostre na tela
quantas vezes cada letra do alfabeto aparece dentro do arquivo.*/


#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){
    string nomeArquivo;
    cout << "Digite o nome do arquivo que deseja saber quantas vezees cada letra do alfabeto aparece: ";
    getline(cin, nomeArquivo);

    ifstream arquivo(nomeArquivo);

    if (!arquivo)
    {
        cerr << "Erro ao abrir arquivo para leitura. ";
        return 1;
    }
    char CaractereLido;
    int contagem[26] = {0};

    while (arquivo.get(CaractereLido))
    {
        if (CaractereLido >= 'a' && CaractereLido <= 'z' || CaractereLido >= 'A' && CaractereLido <= 'Z')
        {
           if (CaractereLido >= 'A' && CaractereLido <= 'Z')
           {
             CaractereLido = CaractereLido + 32;
           }
           
        }
        
        int indice = CaractereLido - 'a';
        contagem[indice]++;
    }
    

    for (int i= 0 ; i < 26; i++)
    {
        if (contagem[i]>0)
        {
            char letra = 'a' + i;
            cout << letra << " apareceu " << contagem[i] << " vezes." << endl;
        }
        
    }
    return 0;
}
