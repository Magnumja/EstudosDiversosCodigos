#include <iostream>  // para entrada e saída padrão (cout/cin)
#include <stdio.h>   // para funções de arquivo (fopen, fputc, fgetc, fclose)
#include <stdlib.h>  // para funções como exit()
#include <conio.h>   // para usar _getch() (lê um caractere sem esperar Enter)


using namespace std;


int main(){
   
FILE *arquivo; //ponteiro para arquivo
arquivo = fopen("../arq2.txt", "w"); // w = write(escrita)

if (arquivo == NULL)
{
    cerr << "Erro ao abrir arquivo.";
    exit(1); // encerra o progrma
}

char caractere;
cout << "Digite os caracteres(ditite 0 para parar): \n";

while (1)
{
    caractere = _getch(); //le caractere sem precisar apertar Enter
    if (caractere == '0') break;
    
    fputc(caractere, arquivo); //escreve o caractere no arquivo
    cout << caractere;
    
}

fclose(arquivo); // fecha o arquivo pos escrita


arquivo = fopen("../arq2.txt", "r"); //abre pra leitura read
if (arquivo == NULL)
{
    cerr << "Errp ao abrir o arquivo.";
    exit(1);
}

cout << "\nConteudo do arquivo: ";

while ((caractere= fgetc(arquivo)) != EOF) // ENQUANTO nao chegar no fim do arquivo
{
    cout << caractere;
}

fclose(arquivo);



}
