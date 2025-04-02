#include <iostream>   // Biblioteca para entrada e saída
#include <fstream>    // Biblioteca para manipulação de arquivos

using namespace std;

int main() {
    // Passo 1: Criar/abrir o arquivo para escrita
    ofstream arquivoSaida("arq.txt"); // Cria ou abre o arquivo para escrita

    if (!arquivoSaida) { // Verifica se o arquivo foi aberto com sucesso
        cout << "Erro ao abrir o arquivo para escrita!" << endl;
        return 1; // Encerra o programa com erro
    }

    // Passo 2: Receber caracteres do usuário até que ele digite '0'
    char caractere;
    cout << "Digite caracteres para salvar no arquivo (digite '0' para parar):" << endl;

    while (true) {
        cin >> caractere; // Lê um caractere do usuário

        if (caractere == '0') { // Se o caractere for '0', sai do loop
            break;
        }

        arquivoSaida << caractere; // Escreve o caractere no arquivo
    }

    // Passo 3: Fechar o arquivo após a escrita
    arquivoSaida.close();

    // Passo 4: Abrir o arquivo novamente para leitura
    ifstream arquivoEntrada("arq.txt"); // Abre o arquivo para leitura

    if (!arquivoEntrada) { // Verifica se o arquivo foi aberto corretamente
        cout << "Erro ao abrir o arquivo para leitura!" << endl;
        return 1; // Encerra o programa com erro
    }

    // Passo 5: Ler e exibir os caracteres do arquivo na tela
    cout << "\nConteúdo do arquivo:" << endl;
    
    while (arquivoEntrada.get(caractere)) { // Lê um caractere por vez
        cout << caractere; // Exibe o caractere na tela
    }

    // Fechar o arquivo após a leitura
    arquivoEntrada.close();

    return 0; // Encerra o programa com sucesso
}
