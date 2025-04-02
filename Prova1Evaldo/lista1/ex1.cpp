/*Escreva um programa que tenha uma sub-rotina para validar a nota de um aluno.
Se a nota informada estiver fora do intervalo de 0 a 10, a função deve retornar falso.
O programa principal deve pedir uma nova entrada até que uma nota válida seja informada.
Além disso, exiba uma mensagem para o usuário indicando se a nota foi aceita ou não.
*/

#include <iostream>

using namespace std;

bool validarnota(float nota)
{
    return(nota >= 0 && nota <= 10);
}

int main()
{
    float nota;

    do
    {
        cout << "De o valor da nota: ";
        cin >> nota;
        if (!validarnota(nota))
        {
            cout << "nota invalida, tente novamente";
        }

    } while (!validarnota(nota));

    cout << "Nota valida, sua nota:" << nota << endl;
    return 0;
}