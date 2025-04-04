#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){
    ofstream arquivoSaida("arq.txt");

    if (!arquivoSaida)
    {
        cout << "Erro ao abrir o arquivo" << endl;
        return 1;
    }

    char caractere;
    cout << "Digite caracteres para salvar no arquivo(digite 0 para parar)";

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
        cout << "Erro ao tentar ler o arquivo" << endl;
        return 1;
    }

    cout << "\nOs cacteres salvos sao: ";

    while (arquivoEntrada.get(caractere))
    {
        cout << caractere;
    }


    arquivoEntrada.close();

    return 0;

    

}