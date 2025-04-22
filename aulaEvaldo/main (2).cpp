#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <conio.h> // incluso, mas não usado aqui
using namespace std;

int main()
{
    FILE *pfile;
    string nomeArq, msg;

    // Solicita o nome do arquivo
    cout << "Informe o nome do arquivo: ";
    cin >> nomeArq;

    // Adiciona .txt ao nome
    nomeArq += ".txt";

    // Abre o arquivo em modo append
    pfile = fopen(nomeArq.c_str(), "a");

    if (pfile == NULL)
    {
        cout << "Erro ao abrir o arquivo!\n";
        return EXIT_FAILURE;
    }

    // Limpa o buffer antes do getline
    cin.ignore();

    // Armazena 3 mensagens no arquivo
    for (int i = 1; i <= 3; i++)
    {
        cout << "Mensagem " << i << ": ";
        getline(cin, msg); // agora usamos string ao invés de fgets
        fprintf(pfile, "Mensagem %d: %s\n", i, msg.c_str());
    }

    fclose(pfile);

    // Reabrindo o arquivo para leitura
    pfile = fopen(nomeArq.c_str(), "r");

    cout << "Leitura do arquivo:\n";

    char c;
    while ((c = getc(pfile)) != EOF)
    {
        cout << c;
    }

    fclose(pfile);
    return 0;
}
