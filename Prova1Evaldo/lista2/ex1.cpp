/*Escreva um programa que:
(a) Crie/abra um arquivo texto de nome &quot;arq.txt&quot;
(b) Permita que o usuário grave diversos caracteres nesse arquivo, até que o
usuário entre com o caractere &#39;0&#39;
(c) Feche o arquivo.
Agora, abra e leia o arquivo, caractere por caractere, e escreva na tela todos os
caracteres armazenados.*/

#include <iostream>   
#include <fstream>    

using namespace std;

int main() {
    
    ofstream arquivoSaida("arq.txt"); 
    if (!arquivoSaida) { 
        cout << "Erro ao abrir o arquivo para escrita!" << endl;
        return 1; 
    }

    
    char caractere;
    cout << "Digite caracteres para salvar no arquivo (digite '0' para parar):" << endl;

    while (true) {
        cin >> caractere; 

        if (caractere == '0') { 
            break;
        }

        arquivoSaida << caractere; 
    }

    
    arquivoSaida.close();

    
    ifstream arquivoEntrada("arq.txt"); 

    if (!arquivoEntrada) { 
        cout << "Erro ao abrir o arquivo para leitura!" << endl;
        return 1; 
    }

    
    cout << "\nConteúdo do arquivo:" << endl;
    
    while (arquivoEntrada.get(caractere)) { 
        cout << caractere; 
    }

  
    arquivoEntrada.close();

    return 0; 
}
