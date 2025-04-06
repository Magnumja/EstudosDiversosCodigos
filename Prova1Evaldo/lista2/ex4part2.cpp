/*Faça um programa que receba do usuário um arquivo texto e mostre na tela
quantas letras são vogais e quantas são consoantes.*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool SeForVogal(char c)
{
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
            c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
}

bool SeForConsoante(char c)
{
    return (c == 'b' || c == 'c' || c == 'd' || c == 'f' || c == 'g' ||
            c == 'h' || c == 'j' || c == 'k' || c == 'l' || c == 'm' || c == 'n' || c == 'p' || c == 'q' || c == 'r' || c == 's' ||
            c == 't' || c == 'v' || c == 'w' || c == 'x' || c == 'y' || c == 'z' || c == 'B' || c == 'C' || c == 'D' || c == 'F' || c == 'G' ||
            c == 'H' || c == 'J' || c == 'K' || c == 'L' || c == 'M' || c == 'N' || c == 'P' || c == 'Q' || c == 'R' || c == 'S' ||
            c == 'T' || c == 'V' || c == 'W' || c == 'X' || c == 'Y' || c == 'Z');
}


int main()
{
    string nomeArquivo;
    cout << "Digite o nome do arquivo: ";
    getline(cin, nomeArquivo);

    ifstream arquivo(nomeArquivo);

    if (!arquivo.is_open())
    {
        cerr << "Erro ao abrir o aquivo para leitura. " << endl;
        return 1;
    }
    
    int contVogal = 0;
    int contConsoante = 0;

    char caractere;
    

    while (arquivo.get(caractere))
    {
        if (SeForConsoante(caractere))
        {
            contConsoante++;
        }
        if (SeForVogal(caractere))
        {
            contVogal++;
        }
        
    }

    arquivo.close();
    


    cout << "O seu texto possui " << contVogal << " vogais e " << contConsoante << " consoantes." << endl;

    return 0;
}
