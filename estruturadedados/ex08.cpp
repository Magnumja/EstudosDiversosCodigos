#include <iostream>

using namespace std;

// criação da minha estrutura do nó
struct address {
    int chave;

    // ponteiros para andar para frente e para trás
    struct address *prox;
    struct address *ant;
};

// crio um apelido para a estrutura
typedef struct address no;

// estrutura de controle da lista
typedef struct {
    no *inicio;
    no *fim;
    int tam;
} LISTA;

// inicializando a lista
void init(LISTA *l) {
    // começo sem nenhum nó
    l->inicio = nullptr;
    l->fim = nullptr;
    l->tam = 0;
}

// inserir no início da lista
void insereInicio(LISTA *l, int valor) {
    // criando um novo nó
    no *novo = new no;

    // colocando o valor dentro do nó
    novo->chave = valor;

    // se a lista estiver vazia
    if (l->inicio == nullptr) {
        // o novo nó não aponta para ninguém
        novo->prox = nullptr;
        novo->ant = nullptr;

        // início e fim recebem o mesmo nó
        l->inicio = novo;
        l->fim = novo;
    }
    else {
        // o novo nó aponta para o antigo início
        novo->prox = l->inicio;

        // como ele será o primeiro, não tem anterior
        novo->ant = nullptr;

        // o antigo início aponta para o novo como anterior
        l->inicio->ant = novo;

        // agora o novo nó vira o início
        l->inicio = novo;
    }

    // aumenta o tamanho da lista
    l->tam++;

    cout << "Elemento inserido no inicio com sucesso!" << endl;
}

// inserir no final da lista
void insereFim(LISTA *l, int valor) {
    // criando um novo nó
    no *novo = new no;

    // colocando o valor dentro do nó
    novo->chave = valor;

    // se a lista estiver vazia
    if (l->inicio == nullptr) {
        // o novo nó não aponta para ninguém
        novo->prox = nullptr;
        novo->ant = nullptr;

        // início e fim recebem o mesmo nó
        l->inicio = novo;
        l->fim = novo;
    }
    else {
        // o novo nó vai ser o último
        novo->prox = nullptr;

        // o anterior dele será o antigo fim
        novo->ant = l->fim;

        // o antigo fim aponta para o novo nó
        l->fim->prox = novo;

        // agora o novo nó vira o fim
        l->fim = novo;
    }

    // aumenta o tamanho da lista
    l->tam++;

    cout << "Elemento inserido no fim com sucesso!" << endl;
}

// imprimir a lista
void imprime(LISTA *l) {
    // atual começa no início da lista
    no *atual = l->inicio;

    cout << "\nTamanho da lista: " << l->tam << endl;

    // verificando se a lista está vazia
    if (l->inicio == nullptr) {
        cout << "Lista vazia!" << endl;
        return;
    }

    // enquanto atual não chegar no final
    while (atual != nullptr) {
        // imprime o valor do nó atual
        cout << atual->chave << " -> ";

        // passa para o próximo nó
        atual = atual->prox;
    }

    cout << "NULL" << endl;
}

int main() {
    LISTA lista;
    int opcao;
    int valor;

    // inicializando a lista antes de usar
    init(&lista);

    // menu fica repetindo até o usuário escolher sair
    do {
        cout << "\n===== MENU =====" << endl;
        cout << "1 - Inserir elemento no fim" << endl;
        cout << "2 - Inserir elemento no inicio" << endl;
        cout << "3 - Imprimir lista" << endl;
        cout << "0 - Sair" << endl;
        cout << "Escolha uma opcao: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                // usuário digita o valor que quer inserir
                cout << "Digite o valor que deseja inserir no fim: ";
                cin >> valor;

                // chama a função para inserir no fim
                insereFim(&lista, valor);
                break;

            case 2:
                // usuário digita o valor que quer inserir
                cout << "Digite o valor que deseja inserir no inicio: ";
                cin >> valor;

                // chama a função para inserir no início
                insereInicio(&lista, valor);
                break;

            case 3:
                // chama a função para imprimir
                imprime(&lista);
                break;

            case 0:
                // encerra o programa
                cout << "Saindo..." << endl;
                break;

            default:
                // caso digite uma opção que não existe
                cout << "Opcao invalida!" << endl;
                break;
        }

    } while (opcao != 0);

    return 0;
}