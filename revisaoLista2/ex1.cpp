/*1. Escreva um programa que: 
(a) Crie/abra um arquivo texto de nome "arq.txt" 
(b)  Permita  que  o  usuário  grave  diversos  caracteres  nesse  arquivo,  até  que  o 
usuário entre com o caractere '0' 
(c) Feche o arquivo. 
Agora, abra e leia o arquivo, caractere por caractere, e escreva na tela todos os 
caracteres armazenados*/


#include <iostream>  // para entrada e saída padrão (cout/cin)
#include <cstdio>    // para funções de arquivo (fopen, fputc, fgetc, fclose)
#include <cstdlib>   // para funções como exit()

using namespace std; // Usando o namespace std, para não precisar digitar 'std::'

int main() {
    // PARTE (a): Crie/abra um arquivo texto de nome "arq.txt"
    // Abre o arquivo para escrita ("w" - write). Se não existir, cria. Se existir, apaga o conteúdo.
    FILE* arquivoEscrita = fopen("arq.txt", "w");

    // Verifica se o arquivo foi aberto com sucesso.
    if (arquivoEscrita == NULL) {
        // Usar cerr para mensagens de erro é uma boa prática.
        cerr << "ERRO: Nao foi possivel abrir o arquivo para escrita!" << endl;
        exit(1); // Encerra o programa com código de erro.
    }

    cout << "Arquivo 'arq.txt' foi aberto com sucesso para escrita." << endl;

    // PARTE (b): Permita que o usuário grave diversos caracteres nesse arquivo,
    // até que o usuário entre com o caractere '0'
    char caractere;
    cout << "Digite caracteres para gravar no arquivo (digite '0' para parar): ";

    do {
        cin >> caractere; // Lê um caractere do teclado.

        if (caractere != '0') {
            // Grava o caractere no arquivo.
            if (fputc(caractere, arquivoEscrita) == EOF) {
                cerr << "ERRO: Nao foi possivel gravar caractere no arquivo!" << endl;
                fclose(arquivoEscrita); // Tenta fechar o arquivo mesmo em erro.
                exit(1);
            }
        }

    } while (caractere != '0'); // Continua o loop enquanto o caractere não for '0'.

    // PARTE (c): Feche o arquivo.
    // Verifica se o fechamento do arquivo foi bem-sucedido.
    if (fclose(arquivoEscrita) == EOF) {
        cerr << "ERRO: Nao foi possivel fechar o arquivo apos a escrita!" << endl;
        exit(1);
    }
    cout << "Arquivo 'arq.txt' fechado apos a escrita." << endl;

    cout << "\n----------------------------------------\n" << endl;

    // Agora, abra e leia o arquivo, caractere por caractere, e escreva na tela todos os
    // caracteres armazenados
    // Abre o arquivo para leitura ("r" - read).
    FILE* arquivoLeitura = fopen("arq.txt", "r");

    // Verifica se o arquivo foi aberto com sucesso para leitura.
    if (arquivoLeitura == NULL) {
        cerr << "ERRO: Nao foi possivel abrir o arquivo para leitura!" << endl;
        exit(1);
    }

    cout << "Arquivo 'arq.txt' foi aberto para leitura." << endl;
    cout << "\nConteudo do arquivo: "; // Coloquei a quebra de linha aqui para melhor formatação.

    // Lê o arquivo caractere por caractere até o final do arquivo (EOF).
    // 'leitura = fgetc(arquivoLeitura)' primeiro atribui e depois compara.
    int leitura; // Deve ser 'int' para acomodar EOF.
    while ((leitura = fgetc(arquivoLeitura)) != EOF) {
        cout << (char)leitura; // Converte para 'char' para imprimir o caractere.
    }

    // Fecha o arquivo de leitura.
    if (fclose(arquivoLeitura) == EOF) {
        cerr << "ERRO: Nao foi possivel fechar o arquivo apos a leitura!" << endl;
        exit(1);
    }

    cout << "\nArquivo 'arq.txt' fechado apos a leitura." << endl;

    return 0; // Retorna 0 para indicar sucesso na execução do programa.
}