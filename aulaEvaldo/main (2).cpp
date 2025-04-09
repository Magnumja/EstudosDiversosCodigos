#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;
int main()
{
    FILE *pfile;
    char nomeArq[50],msg[50];
    //Apenas solicitar o nome do arquivo
    cout<<"Informe o nome do arquivo: ";
    cin>>nomeArq;
    //Utilizar apenas arquivos .txt
    strcat(nomeArq,".txt");
    //Abrir o arquivo. Caso n�o exista ele ser�
    //criado
    //pfile=fopen(nomeArq,"r");
    pfile=fopen(nomeArq,"a");
    //Verificar se o arquivo foi aberto corretamente
    if(pfile==NULL)
    {
        cout<<"Erro ao abrir o arquivo!\n";
        return EXIT_FAILURE;
    }
    //Armazenar 3 mensagens no arquivo.
    fflush(stdin);
    for(int i=1;i<=3;i++)
    {
        cout<<"Mensagem "<<i<<": ";
        fgets(msg,50,stdin);
        fprintf(pfile,"Mensagem %d: %s",i,msg);
    }
    //Fechar o arquivo
    fclose(pfile);
    //Realizar a leitura do arquivo
    pfile=fopen(nomeArq,"r");
    cout<<"Leitura do arquivo: \n";
    char c;
    do{
        c=getc(pfile);
        cout<<c;
    }while(c!=EOF);
    fclose(pfile);
    return 0;
}
