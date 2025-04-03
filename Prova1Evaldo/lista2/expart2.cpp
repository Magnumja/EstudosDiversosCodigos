#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    // criar ou abrir arquivo para escrita
    ofstream arquivoSaida("arq.txt"); //cria ou abre o arquivo para a escrita

    if (!arquivoSaida) {
        cout << "Erro ao abrir o arquivo para escrita!";
        return 1;
    }

    char caractere;
    cout << "Digite caracteres para salvar no aquivo(gitite 0 para poder parar): " << endl;

    while (1)
    {
       cin >> caractere;
       if (caractere == '0')
       {
        break;
       }

       arquivoSaida << caractere;
       
    }

    arquivoSaida.close();

    ifstream arquivoEntrada("arq.txt");

    if (!arquivoEntrada)
    {
        cout << "Erro ao abrir aquivo para leitura";
        return 1;
    }

    cout << "\nConteudo do arquivo salvo foi: " << endl;

    while (arquivoEntrada.get(caractere))
    {
       cout << caractere;
    }

    arquivoEntrada.close();

    return 0;
    
    
    
    
}