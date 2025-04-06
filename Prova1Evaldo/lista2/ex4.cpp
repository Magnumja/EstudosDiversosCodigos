/*Faça um programa que receba do usuário um arquivo texto e mostre na tela
quantas letras são vogais e quantas são consoantes.*/


#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool SeForVogal(char c){
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
        c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
}

bool SeForConsoante(char c){
    return (c == 'b' || c == 'c' || c == 'd' || c == 'f' || c == 'g' ||
        c == 'h' || c == 'j' || c == 'k' || c == 'l' || c == 'm' || c == 'n' || c == 'p' || c == 'q' || c == 'r' || c == 's' ||
            c == 't' || c == 'v' || c == 'w' || c == 'x' || c == 'y' || c == 'z' || c == 'B' || c == 'C' || c == 'D' || c == 'F' || c == 'G' ||
            c == 'H' || c == 'J' || c == 'K' || c == 'L' || c == 'M' || c == 'N' || c == 'P' || c == 'Q' || c == 'R' || c == 'S' ||
                c == 'T' || c == 'V' || c == 'W' || c == 'X' || c == 'Y' || c == 'Z');
}

int main()
{
    string texto;
    int contconsoante = 0;
    int contvogal = 0;
    cout << "Escreva o texto que deseja e te direi quantas consoantes e vogais ele possui: ";
    getline (cin,texto);

    for (int i = 0; i < texto.length(); i++)
    {
        if (SeForConsoante(texto[i]))
        {
            contconsoante++;
        }
        if (SeForVogal(texto[i]))
        {
            contvogal++;
        }
    }

    cout << "O seu texto possui " << contvogal << " vogais e " << contconsoante << " consoantes." << endl;

    return 0;
    


}