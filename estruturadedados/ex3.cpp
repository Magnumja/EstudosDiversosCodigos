#include <iostream>
using namespace std;

struct REGISTRO
{
    int chave;
};

// função para buscar um valor na lista
// percorre a lista inteira procurando a chave
int buscar(REGISTRO lista[], int tl, int valor)
{
    // percorre a lista posição por posição
    for (int i = 0; i < tl; i++)
    {
        // se encontrar o valor que estamos procurando
        if (lista[i].chave == valor)
        {
            // retorna a posição onde ele está
            return i;
        }
    }

    // se terminou o for e não achou, retorna -1
    return -1;
}

// função para remover um elemento da lista
// aqui não pode deixar "buracos", então precisamos deslocar os elementos
bool remover(REGISTRO lista[], int &tl, int valor)
{
    // primeiro tenta achar o valor na lista
    int pos = buscar(lista, tl, valor);

    // se não encontrou, não tem o que remover
    if (pos == -1)
    {
        return false;
    }

    // agora desloca todos os elementos uma posição para a esquerda
    // isso serve para fechar o espaço do elemento removido
    for (int i = pos; i < tl - 1; i++)
    {
        lista[i] = lista[i + 1];
    }

    // diminui o tamanho lógico da lista
    tl--;

    return true;
}

int main()
{
    REGISTRO lista[10]; // criando a lista com capacidade para 10
    int tl = 5; // tamanho lógico da lista (quantos elementos realmente tem)

    // preenchendo a lista manualmente só para teste
    lista[0].chave = 10;
    lista[1].chave = 20;
    lista[2].chave = 30;
    lista[3].chave = 40;
    lista[4].chave = 50;

    int valor;

    // pedindo um valor para buscar
    cout << "Digite um valor para buscar: ";
    cin >> valor;

    int pos = buscar(lista, tl, valor);

    if (pos != -1)
        cout << "Achei na posicao " << pos << endl;
    else
        cout << "Nao encontrei esse valor na lista" << endl;

    // agora testando a remoção
    cout << "Digite um valor para remover: ";
    cin >> valor;

    if (remover(lista, tl, valor))
        cout << "Removido com sucesso" << endl;
    else
        cout << "Nao foi possivel remover (valor nao existe)" << endl;

    // mostrando como ficou a lista depois da remoção
    cout << "Lista final:" << endl;

    for (int i = 0; i < tl; i++)
    {
        cout << lista[i].chave << " ";
    }

    cout << endl;

    return 0;
}