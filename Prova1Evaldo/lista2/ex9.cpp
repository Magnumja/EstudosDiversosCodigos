#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    string nomeArquivo1, nomeArquivo2, nomeArquivoSaida;

    
    cout << "Digite o nome do primeiro arquivo: ";
    getline(cin, nomeArquivo1);

    cout << "Digite o nome do segundo arquivo: ";
    getline(cin, nomeArquivo2);

    cout << "Digite o nome do arquivo de saida: ";
    getline(cin, nomeArquivoSaida);

  
    ifstream arquivo1(nomeArquivo1);
    ifstream arquivo2(nomeArquivo2);

    if (!arquivo1 || !arquivo2) {
        cerr << "Erro ao abrir um dos arquivos de entrada." << endl;
        return 1;
    }

   
    ofstream arquivoSaida(nomeArquivoSaida);
    if (!arquivoSaida) {
        cerr << "Erro ao criar o arquivo de saída." << endl;
        return 1;
    }

    char caractere;

   
    while (arquivo1.get(caractere)) {
        arquivoSaida << caractere;
    }

  
    while (arquivo2.get(caractere)) {
        arquivoSaida << caractere;
    }

   
    arquivo1.close();
    arquivo2.close();
    arquivoSaida.close();

    cout << "Conteúdo dos arquivos foi combinado com sucesso!" << endl;

    return 0;
}
