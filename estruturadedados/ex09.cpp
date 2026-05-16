#include <iostream>
using namespace std;

// estrutura do no da lista duplamente encadeada
// cada no guarda um valor (chave) e dois ponteiros:
// um pro proximo no e um pro no anterior
struct address {
    int chave;         // o valor que o no armazena
    struct address *prox; // ponteiro pro proximo no da lista
    struct address *ant;  // ponteiro pro no anterior da lista
};

// criando um apelido pra nao precisar escrever "struct address" toda hora
typedef struct address no;

// estrutura de controle da lista
// ela guarda o inicio, o fim e o tamanho atual
// sem ela ficaria dificil saber onde a lista comeca e termina
typedef struct {
    no *inicio; // aponta pro primeiro no da lista
    no *fim;    // aponta pro ultimo no da lista
    int tam;    // quantos elementos tem na lista no momento
} LISTA;

// funcao de inicializacao da lista
// sempre chamar isso antes de usar a lista
// se nao inicializar, os ponteiros ficam com lixo de memoria
void init(LISTA *l) {
    l->inicio = nullptr; // lista vazia, entao inicio aponta pra nada
    l->fim = nullptr;    // mesmo pro fim
    l->tam = 0;          // zero elementos no comeco
}

// funcao para inserir um novo no no final da lista
// recebe a lista e o valor a ser inserido
void insereFim(LISTA *l, int valor) {
    // aloca memoria pro novo no usando new (equivalente ao malloc em C)
    no *novo = new no;

    // caso especial: lista esta vazia
    // o novo no vai ser ao mesmo tempo o inicio e o fim
    if (l->inicio == nullptr) {
        novo->prox = nullptr; // nao tem proximo, e o unico elemento
        novo->ant = nullptr;  // nao tem anterior, e o primeiro
        l->inicio = novo;     // atualiza o inicio da lista de controle
        l->fim = novo;        // atualiza o fim da lista de controle
    } else {
        // lista ja tem pelo menos um elemento
        // o novo no vai ser encaixado depois do atual ultimo
        novo->prox = nullptr;  // novo no e o ultimo, entao proximo e nulo
        novo->ant = l->fim;    // o anterior do novo e o atual ultimo no

        // o antigo ultimo no agora aponta pro novo como seu proximo
        l->fim->prox = novo;

        // atualiza o fim da lista de controle pro novo no
        l->fim = novo;
    }

    novo->chave = valor; // atribui o valor ao no depois de encadear tudo
    l->tam++;            // incrementa o tamanho da lista
}

// funcao para remover o ultimo elemento da lista
// precisa atualizar o novo fim e desconectar o no removido
void removeFim(LISTA *l) {
    // verifica se a lista esta vazia antes de tentar remover
    if (l->fim == nullptr) {
        cout << "Lista vazia!" << endl;
        return; // nao tem nada pra remover, sai da funcao
    }

    no *atual = l->fim; // guarda o ponteiro do no que vai ser removido

    // verifica se e o unico elemento da lista
    // se ant e nullptr, nao tem no anterior, ou seja, so tem esse
    if (atual->ant == nullptr) {
        init(l); // reinicia a lista de controle, fica zerada
    } else {
        // tem mais de um elemento na lista
        // o novo fim passa a ser o no anterior ao que vai ser removido
        l->fim = atual->ant;

        // o novo ultimo no nao tem mais proximo, entao aponta pra null
        l->fim->prox = nullptr;

        l->tam--; // decrementa o tamanho da lista
    }

    // libera a memoria do no removido
    // importante fazer isso pra nao vazar memoria (memory leak)
    delete atual;
}

// funcao para remover o primeiro elemento da lista
// logica espelhada do removeFim, mas operando no inicio
void removeInicio(LISTA *l) {
    // verifica se a lista esta vazia antes de tentar remover
    if (l->inicio == nullptr) {
        cout << "Lista vazia!" << endl;
        return; // nao tem nada pra remover
    }

    no *atual = l->inicio; // guarda o ponteiro do no que vai ser removido

    // verifica se existe apenas um elemento na lista
    // se prox e nullptr, nao tem proximo, ou seja, e o unico no
    if (atual->prox == nullptr) {
        init(l); // reinicia a lista, fica zerada igual no removeFim
    } else {
        // tem mais de um elemento
        // o novo inicio passa a ser o proximo do no que sera removido
        l->inicio = atual->prox;

        // o novo primeiro no nao tem anterior, entao aponta pra null
        // se nao fizer isso, fica um ponteiro solto pra um no deletado
        l->inicio->ant = nullptr;

        l->tam--; // decrementa o tamanho da lista
    }

    // libera a memoria do no removido da heap
    delete atual;
}

// funcao de impressao da lista
// percorre do inicio ao fim usando o ponteiro prox
void imprime(LISTA *l) {
    no *atual = l->inicio; // comeca pelo primeiro no

    cout << "\nTamanho atual da lista: " << l->tam << endl;

    // imprime o NULL do lado esquerdo pra representar que nao tem nada antes do inicio
    cout << "NULL <- ";

    // percorre a lista enquanto atual nao for nulo
    while (atual != nullptr) {
        cout << atual->chave;
        if (atual->prox != nullptr) cout << " <-> "; // separador entre nos
        atual = atual->prox; // avanca pro proximo no
    }

    // NULL no final representa que nao tem nada depois do ultimo no
    cout << " -> NULL\n";
}

// menu interativo para testar todas as funcoes da lista
// usa do/while pra garantir que aparece pelo menos uma vez
void menu(LISTA *l) {
    int opcao, valor;

    do {
        // exibe as opcoes disponiveis pro usuario
        cout << "\n===== MENU =====\n";
        cout << "1 - Inserir no fim\n";
        cout << "2 - Remover do fim\n";
        cout << "3 - Remover do inicio\n";
        cout << "4 - Imprimir lista\n";
        cout << "0 - Sair\n";
        cout << "Opcao: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                cout << "Valor a inserir: ";
                cin >> valor;
                insereFim(l, valor); // chama a insercao no fim com o valor digitado
                break;
            case 2:
                removeFim(l); // remove o ultimo elemento
                cout << "Removido do fim.\n";
                break;
            case 3:
                removeInicio(l); // remove o primeiro elemento
                cout << "Removido do inicio.\n";
                break;
            case 4:
                imprime(l); // mostra o estado atual da lista
                break;
            case 0:
                cout << "Encerrando o programa.\n";
                break;
            default:
                // qualquer numero fora do menu cai aqui
                cout << "Opcao invalida! Tente novamente.\n";
        }

    } while (opcao != 0); // continua ate o usuario digitar 0
}

int main() {
    LISTA lista1; // declara a lista na stack

    // inicializa antes de qualquer operacao
    // sem isso os ponteiros tem valor indefinido
    init(&lista1);

    // chama o menu passando o endereco da lista
    menu(&lista1);

    return 0;
}