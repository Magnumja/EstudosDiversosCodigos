// Exemplo simples de passagem por valor e por ponteiro.
#include <iostream>

using namespace std;

struct REGISTRO
{
    int chave;
};

void alteraPorValor(REGISTRO r)
{
    r.chave = 10;
    cout << "Na funcao por valor " << r.chave << endl;
}

void alteraPorPonteiro(REGISTRO *r)
{
    r->chave = 20;
    cout << "Na funcao ponteiro " << r->chave << endl;
}

void alteraPorReferencia(REGISTRO &r)
{
    r.chave = 30;
    cout << "Na funcao referencia " << r.chave << endl;
}

int main()
{

    REGISTRO meureq;

    meureq.chave = 0;

    alteraPorValor(meureq);

    // A passagem por valor não altera o valor da variável na main, pois a função recebe uma cópia da variável.
    cout << "Na main: " << meureq.chave << endl;

    // A passagem por ponteiro altera o valor da variável na main, pois a função recebe um ponteiro para a variável.
    alteraPorPonteiro(&meureq);

    cout << "Na main: " << meureq.chave << endl;
    // Passagem por referencia é mais simples, não precisa usar o operador de endereço e indireção.
    alteraPorReferencia(meureq);

    cout << "Na main: " << meureq.chave << endl;
}