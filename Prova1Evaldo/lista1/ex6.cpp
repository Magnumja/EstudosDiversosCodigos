/*Escreva um programa com um procedimento que receba três notas e uma letra como parâmetros.
Se a letra for “A”, calcule e retorne a média aritmética.
Se for “P”, retorne a média ponderada considerando os pesos 2, 3 e 4 para as respectivas notas.
*/

#include <iostream>

using namespace std;

void notas(int n1, int n2, int n3, char caractere)
{
    if (caractere == 'A')
    {
        int mediaA = (n1 + n2 + n3) / 3;
        cout << "O valor da media aritmetica foi de " << mediaA << endl;
    }
    if (caractere == 'P')
    {
        float mediaP = (2 * n1 + 3 * n2 + 4 * n3) / 9;
        cout << "O resultado da media ponderada foi de " << mediaP << endl;
    }
}
bool verificarCaractere(char caractere)
{
    return (caractere == 'A' || caractere == 'P');
}
bool verificarNota(int n1, int n2, int n3)
{
    return ((n1 >= 0 && n1 <= 10) && (n2 >= 0 && n2 <= 10) && (n3 >= 0 && n3 <= 10));
}
int main()
{
    int n1, n2, n3;
    char caractere;

    do
    {
        cout << "Poderia dizer a nota 1, 2 e 3 respectivamente: ";
        cin >> n1 >> n2 >> n3;

        if (!verificarNota(n1,n2,n3))
        {
            cout << "Erro tente novamente! \n";
        }

    } while (!verificarNota(n1,n2,n3));
    cout << "\n";

    do
    {
        cout << "Poderia agora me informar seu caractere, P para media ponderada e A para media aritmetica: ";
        cin >> caractere;

        if (!verificarCaractere(caractere))
        {
            cout << "Erro tente novamente! \n";
        }

    } while (!verificarCaractere(caractere));

    notas(n1, n2, n3, caractere);

    return 0;
}