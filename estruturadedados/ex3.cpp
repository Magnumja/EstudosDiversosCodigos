#include <iostream>
using namespace std;

struct REGISTRO
{
    int chave;
};

int buscar(REGISTRO lista[], int tl, int valor)
{
    for (int i = 0; i < tl; i++)
    {
        if (lista[i].chave == valor)
        {
            return i;
        }
    }

    return -1;
}

bool remover(REGISTRO lista[], int &tl, int valor)
{
    int pos = buscar(lista, tl, valor);

    if (pos == -1)
    {
        return false;
    }

    for (int i = pos; i < tl - 1; i++)
    {
        lista[i] = lista[i + 1];
    }

    tl--;

    return true;
}

int main()
{
    REGISTRO lista[10];
    int tl = 5;

    lista[0].chave = 10;
    lista[1].chave = 20;
    lista[2].chave = 30;
    lista[3].chave = 40;
    lista[4].chave = 50;

    int valor;

    cout << "Digite um valor para buscar: ";
    cin >> valor;

    int pos = buscar(lista, tl, valor);

    if (pos != -1)
    {
        cout << "Valor encontrado na posicao " << pos << endl;
    }
    else
    {
        cout << "Valor nao encontrado" << endl;
    }

    cout << "Digite um valor para remover: ";
    cin >> valor;

    if (remover(lista, tl, valor))
    {
        cout << "Valor removido com sucesso" << endl;
    }
    else
    {
        cout << "Valor nao encontrado para remover" << endl;
    }

    cout << "Lista final:" << endl;

    for (int i = 0; i < tl; i++)
    {
        cout << lista[i].chave << " ";
    }

    cout << endl;

    return 0;
}
