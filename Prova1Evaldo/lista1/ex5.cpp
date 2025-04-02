/*Escreva um programa com um procedimento que receba três notas e uma letra como parâmetros.
Se a letra for “A”, calcule e retorne a média aritmética.
Se for “P”, retorne a média ponderada considerando os pesos 2, 3 e 4 para as respectivas notas.
*/

#include <iostream>

using namespace std;

void SeForA(float n1, float n2, float n3, float &MediaAritmetica)
{
    MediaAritmetica = (n1 + n2 + n3) / 3;
}

void SeForP(float n1, float n2, float n3, float &MediaPonderada)
{
    MediaPonderada = (2 * n1 + 3 * n2 + 4 * n3) / 9;
}

bool ValidarCaractere(char carac)
{
    return (carac != 'A' && carac != 'P' && carac != 'S');
}

int main()
{
    char carac;
    float n1, n2, n3, MediaAritmetica, MediaPonderada;

    cout << "Digite as 3 notas e depois escolha o que deseja: ";
    cin >> n1 >> n2 >> n3;

    do
    {
        cout << "\nA - Media aritmetica\n";
        cout << "P - Media ponderada\n";
        cout << "S - Sair\n";
        cout << "Digite: ";
        cin >> carac;

        if (ValidarCaractere(carac))
        {
            cout << "Caractere Invalido, tente novamente";
            continue;
        }
        

        if (carac == 'A')
        {
            SeForA(n1, n2, n3, MediaAritmetica);
            cout << "Media Aritmetica: " << MediaAritmetica << endl;
        }
        else if (carac == 'P')
        {
            SeForP(n1, n2, n3, MediaPonderada);
            cout << "Media ponderada: " << MediaPonderada << endl;
        }
        else if (carac == 'S')
        {
            cout << "Foi um prazer te servir!";
            break;
        }
        

    } while (ValidarCaractere(carac));
}