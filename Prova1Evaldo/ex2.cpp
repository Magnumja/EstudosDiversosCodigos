/*Crie um programa que contenha uma sub-rotina para validar a entrada de caracteres.
Somente as letras “A”, “a”, “P” ou “p” são permitidas.
Caso o usuário informe um caractere diferente, a função deve retornar falso e solicitar uma nova entrada.
Informe ao usuário se o caractere foi aceito ou não.*/

#include <iostream>

using namespace std;

bool ValidarCaractere(char carac)
{
    return (carac == 'A', carac == 'a', carac = 'P', carac == 'p');
}

int main()
{
    char carac;

    do
    {
        cout << "\n Me fale o caractere desejado (A,a,P,p):  ";
        cin >> carac;

        if (!ValidarCaractere(carac))
        {
            cout << "\n Caractere invalido, tente novamente! ";
        }
        
    } while (!ValidarCaractere(carac));

    cout << "Caractere aceito: " << carac << endl;

    return 0;
    
}