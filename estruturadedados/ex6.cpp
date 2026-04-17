#include <iostream>
#include <stdlib.h> // trabalhar com nó

using namespace std;

/*
   Eu criava o nó novo e até apontava ele para o resto da lista...
   Mas eu esquecia de avisar a própria lista que o início dela tinha mudado!
Faltava a linha: l->inicio = novo;
   Sem isso, a lista continuava apontando para o elemento velho e o meu 
   nó novo ficava perdido na memória do computador. */

// estrutura dos nossos dados (agenda)
struct address {
    int chave;
    // outros campos
    char nome[30];
    char rua[30];
    char email[80];
    struct address *prox;
};

// defino que a estrutura da agenda é um nó
typedef struct address no;

// Lista de controle (cabeça)
typedef struct {
    no *inicio; // aponta para o início
    int tam;    // quantidade de elementos na lista
} LISTA;

// inicializar
void init(LISTA *l) {
    l->inicio = NULL;
    l->tam = 0;
}

// inserir no início passando um valor
void insere_ini(LISTA *l, int valor){
    // Criar um novo nó com cast
    no *novo = (no*) malloc(sizeof(no));
    
    // inserir a chave no novo nó
    novo->chave = valor;
    
    // o próximo do novo aponta o início da Lista
    novo->prox = l->inicio;
    
    // [AQUI ESTAVA O ERRO - AGORA CORRIGIDO]
    // Atualiza a lista para reconhecer o novo nó como sendo o início oficial
    l->inicio = novo; 
    
    // atualiza a quantidade de elemento
    l->tam++;
}

// Inserir no fim
void insere_fim(LISTA *l, int valor) {
    // Criar um novo nó
    no *novo = (no*) malloc(sizeof(no));
    no *atual;
    
    // insere o valor novo ao nó criado
    novo->chave = valor;
    // o próximo do novo é NULL
    novo->prox = NULL;

    // Verificar se a lista é vazia
    if (l->inicio == NULL){
       l->inicio = novo; // o novo é início
    } else { // se não for vazia
        atual = l->inicio;
        // enquanto houver elementos próximos na lista
        while(atual->prox != NULL){
            atual = atual->prox;
        }
        // chegou no último elemento
        atual->prox = novo;
    }
    // atualiza a quantidade de elementos
    l->tam++;
}

void imprime(LISTA *l) {
    no *atual;
    atual = l->inicio;
    cout << "Tamanho da lista: " << l->tam << endl;
    
    while (atual != NULL){
        // Coloquei um espaçamento " -> " para ficar mais fácil de ler na tela
        cout << atual->chave << " -> ";
        atual = atual->prox;
    }
    cout << "FIM" << endl;
}

int main()
{
    LISTA minhaLista;

    // 1. Inicia a lista (vazia)
    init(&minhaLista);

    // 2. Insere elementos usando as duas funções
    cout << "Inserindo o numero 10 no inicio..." << endl;
    insere_ini(&minhaLista, 10);
    
    cout << "Inserindo o numero 20 no inicio..." << endl;
    insere_ini(&minhaLista, 20); // 20 empurra o 10
    
    cout << "Inserindo o numero 30 no final..." << endl;
    insere_fim(&minhaLista, 30);
    
    cout << "Inserindo o numero 40 no final..." << endl;
    insere_fim(&minhaLista, 40); // 40 vai pro fim de tudo

    // 3. Manda imprimir para provar que funcionou!
    cout << "\n--- RESULTADO FINAL NA MEMORIA ---" << endl;
    imprime(&minhaLista);

    return 0;
}
