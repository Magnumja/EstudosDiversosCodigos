/*Faça um programa que receba do usuário um arquivo texto e mostre na tela
quantas letras são vogais e quantas são consoantes*/


#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>


using namespace std;

int main()
{
    FILE *arquivo;
    string nomeArquivo;
    cout << "Qual o nome do arquivo que deseja abrir";
         cin >> nomeArquivo;

    arquivo = fopen(nomeArquivo.c_str(), "r");

    if(arquivo == NULL)
    {
        cout << "Erro ao abrir arquivo para leitura" << endl;
        return 1;
    }


    char caractere;
    int contarVogais = 0;
    int contarConsoantes =0;

    while((caractere = fgetc(arquivo))!= EOF)
    {
        if(caractere == 'a' || caractere == 'e' || caractere == 'i' || caractere == 'o' || caractere == 'u' || caractere == 'A' || caractere == 'E' || caractere == 'I' || caractere == 'O' || caractere == 'U')
        {
            contarVogais ++;
        }
        else{
            contarConsoantes++;
        }
    }

    cout << "O arquivo possui " << contarVogais << " vogais e " << contarConsoantes << " consoantes." << endl;

    return 0;
}
