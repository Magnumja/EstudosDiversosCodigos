/* Faça um programa que receba do usuário um arquivo texto 
e mostre na tela quantas linhas esse arquivo possui. 
*/

#include <iostream>  // para entrada e saída padrão (cout/cin)
#include <stdio.h>   // para funções de arquivo (fopen, fputc, fgetc, fclose)
#include <stdlib.h>  // para funções como exit()
#include <conio.h>   // para usar _getch() (lê um caractere sem esperar Enter)

using namespace std;

int main(){
   
    FILE*arquivo;
    string nomeArquivo;
    /*A função fopen() é da linguagem C, e ela espera um const char* 
    como argumento (ou seja, um ponteiro para uma sequência de caracteres).
    O tipo string do C++ não é automaticamente compatível, mas a gente pode converter usando o método .c_str().*/
    cout << "Digite o nome do arquivo que deseja abrir: ";
    cin >> nomeArquivo;
    arquivo = fopen(nomeArquivo.c_str(), "r");

    if (arquivo == NULL)
    {
        cerr << "Erro ao abrir o arquivo. \n";
        exit(1);
    }
    char caractere;
    int contadorLinhas = 0;
    while ((caractere = fgetc(arquivo))!=EOF)
    {
        if (caractere == '\n')
        {
            contadorLinhas++;
        }
        
    }
    
    cout << "O arquivo possui " << contadorLinhas + 1 << " linhas. \n";

    fclose(arquivo);

    return 0;
    
    

    

}