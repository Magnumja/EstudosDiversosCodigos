/*Faça um programa que receba do usuário um arquivo texto e 
mostre na tela quantas letras são vogais. 
*/

#include <iostream>  // para entrada e saída padrão (cout/cin)
#include <stdio.h>   // para funções de arquivo (fopen, fputc, fgetc, fclose)
#include <stdlib.h>  // para funções como exit()
#include <conio.h>   // para usar _getch() (lê um caractere sem esperar Enter)

using namespace std;

int main(){
    FILE*arquivo;
    string nomeArquivo;
    cout << "Digite o nome do arquivo de texto que deseja saber: ";
    cin >> nomeArquivo;

    arquivo = fopen(nomeArquivo.c_str(), "r");
    if (arquivo == NULL)
    {
        cerr << "Erro ao abrir arquivo. ";
        exit(1);
    }

    char caractere;
    int contadorVogal = 0;
    while ((caractere = fgetc(arquivo))!=EOF)
    {
        if (caractere == 'a' || caractere == 'e' || caractere == 'i' ||
            caractere == 'o' || caractere == 'u' ||
            caractere == 'A' || caractere == 'E' || caractere == 'I' ||
            caractere == 'O' || caractere == 'U')
        {
            contadorVogal++;
        }
      
        
    }

    cout << "O arquivo de texto possui " << contadorVogal << " vogais." << endl;

    fclose(arquivo);

    return 0;
    

}