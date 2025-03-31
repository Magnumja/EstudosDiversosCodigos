/*Escreva um programa que tenha uma sub-rotina para validar a nota de um aluno.
Se a nota informada estiver fora do intervalo de 0 a 10, a função deve retornar falso.
O programa principal deve pedir uma nova entrada até que uma nota válida seja informada.
Além disso, exiba uma mensagem para o usuário indicando se a nota foi aceita ou não.
*/

#include <iostream>

using namespace std;

bool ValidarNota(float nota)
{
    return (nota >= 0 && nota <= 10);
}

int main()
{
    float nota;
    do
    {
        cout << "Me informe sua nota, por favor: ";
        cin >> nota;
        if (!ValidarNota(nota))
        {
            cout << "\n Sua nota nao foi aceita. Tente novamente \n";
        }

    } while (!ValidarNota(nota));
    
    cout << "Nota aceita: " << nota << endl;

    return 0;
}