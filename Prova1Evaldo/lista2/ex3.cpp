/*Faça um programa que receba do usuário um arquivo texto e mostre na tela
quantas letras são vogais.*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool ehVogal(char c)
{
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
            c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
}

int main()
{
    string texto;
    cout << "Digite o texto que deseja:\n";
    getline(cin, texto);

    int cont = 0;

    for (int i = 0; i < texto.length(); i++)
    {
        if (ehVogal(texto[i]))
        {
            cont++;
        }
        
    }
    

    

    cout << "O texto possui " << cont << " vogais" << endl;

    return 0;
    

}