/*Faça um programa que leia o conteúdo de um arquivo e crie um arquivo com o
mesmo conteúdo, mas com todas as letras minúsculas convertidas para maiúsculas.
Os nomes dos arquivos serão fornecidos, via teclado, pelo usuário. A função que
converte maiúscula para minúscula é o toupper(). Ela é aplicada em cada caractere
da string.*/
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

using namespace std;

int main(){
    string nomeArquivoEntrada, nomeArquivoSaida;

    cout << "Digite os nomes dos arquivos de entrada e saida para a conversao: ";
    getline(cin, nomeArquivoEntrada);

    cout << "Agora o de saida: ";
    getline(cin, nomeArquivoSaida);

    ifstream arquivo(nomeArquivoEntrada);
    if (!arquivo)
    {
        cerr << "Erro ao abrir arquivo para leitura.";
        return 1;
    }

    ofstream arquivo2(nomeArquivoSaida);
    if (!arquivo2)
    {
        cout << "Erro ao abrir o arquivo de saída." << endl;
        return 1;
    }

    char caractere;

    while (arquivo.get(caractere))
    {
        caractere = toupper(caractere); 
        arquivo2 << caractere;
    }

    arquivo.close();
    arquivo2.close();

    return 0;
}
