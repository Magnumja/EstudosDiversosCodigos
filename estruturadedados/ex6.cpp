#include <iostream>
#include <stdlib.h> // trabalhar com nó e malloc

using namespace std;

// estrutura dos nossos dados
// agenda
struct address {
    int chave;
    // outros campos
    char nome[30];
    char rua[30];
    char email[80];
    // o ponteiro que liga um vagão ao outro
    struct address *prox; 
};

// defino que a estrutura da agenda é um nó
typedef struct address no;

// Lista de controle (cabeça / locomotiva)
typedef struct {
    no *inicio; // aponta para o início da lista
    int tam;    // quantidade de elementos na lista
} LISTA;

// Métodos que vamos utilizar
// 1 - inicializar
// 2 - inserir no início
// 3 - inserir no final
// 4 - imprimir

// 1. inicializar
void init(LISTA *l) {
    l->inicio = NULL; // a lista começa vazia
    l->tam = 0;       // tamanho zero
}

// 2. inserir no início
// passando a lista por referência e um valor
void insere_ini(LISTA *l, int valor){
    // PRIMEIRA tarefa: Criar um novo nó na memória
    // NECESSÁRIO fazer um cast para nó para o C++ entender
    no *novo = (no*) malloc(sizeof(no));
    
    // inserir a chave (o valor) no novo nó
    novo->chave = valor;
    
    // PULO DO GATO
    // o próximo do novo aponta para quem era o início antigo da Lista
    novo->prox = l->inicio;
    
    // ATUALIZAÇÃO CRÍTICA
    // agora, a própria lista precisa reconhecer que o novo nó é o seu novo início
    l->inicio = novo; 
    
    // atualiza a quantidade de elementos
    l->tam++;
}

// 3. Inserir no fim
void insere_fim(LISTA *l, int valor) {
    // PRIMEIRA tarefa: Criar um novo nó
    no *novo = (no*) malloc(sizeof(no));
    no *atual; // ponteiro auxiliar para percorrer a lista
    
    // insere o valor novo ao nó criado
    novo->chave = valor;
    // como ele vai para o fim, o próximo dele obrigatoriamente é Nulo
    novo->prox = NULL;

    // Verificar se a lista é vazia
    if (l->inicio == NULL){
       l->inicio = novo; // se for vazia, o novo é o próprio início
    } else { // se não for vazia
        atual = l->inicio; // começa a busca pelo início
        
        // precisa percorrer a lista até chegar
        // no nó onde o próximo é Nulo (ou seja, o último vagão)
        while(atual->prox != NULL){
            atual = atual->prox; // avança para o próximo
        }
        // chegou no último elemento! Agora engata o novo nó nele
        atual->prox = novo;
    }
    // atualiza a quantidade de elementos
    l->tam++;
}

// 4. Imprimir
void imprime(LISTA *l) {
    // verifica se tem algo para imprimir
    if (l->tam == 0) {
        cout << "A lista esta vazia.\n";
        return;
    }
    
    no *atual; // auxiliar para percorrer
    atual = l->inicio; // começa do início
    
    cout << "Tamanho da lista: " << l->tam << endl;
    cout << "Elementos: ";
    
    // enquanto houver elementos (atual for diferente de Nulo)
    while (atual != NULL){
        cout << "[" << atual->chave << "] -> ";
        atual = atual->prox; // pula para o próximo nó
    }
    cout << "NULL\n"; // marca visual do fim da lista
}

// Função Principal e Menu
int main()
{
    LISTA minhaLista; // criação da nossa lista de controle
    int opcao;        // guarda a escolha do menu
    int valor;        // guarda o valor digitado pelo usuário

    // iniciar a manipulação estrutural da lista
    init(&minhaLista);

    // Loop principal do programa (faz enquanto o usuário não digitar 0)
    do {
        // Exibição visual do Menu
        cout << "\n====== MENU DA LISTA ENCADEADA ======\n";
        cout << "1. Inserir elemento no INICIO\n";
        cout << "2. Inserir elemento no FINAL\n";
        cout << "3. Imprimir a lista\n";
        cout << "0. Sair do programa\n";
        cout << "Escolha uma opcao: ";
        cin >> opcao; // captura a ação do usuário

        // Avalia qual opção foi escolhida
        switch(opcao) {
            case 1:
                cout << "Digite o valor (chave) para o inicio: ";
                cin >> valor;
                insere_ini(&minhaLista, valor); // chama a função de inserir
                cout << "[SUCESSO] Valor " << valor << " inserido no inicio!\n";
                break;

            case 2:
                cout << "Digite o valor (chave) para o final: ";
                cin >> valor;
                insere_fim(&minhaLista, valor); // chama a função de inserir
                cout << "[SUCESSO] Valor " << valor << " inserido no final!\n";
                break;

            case 3:
                cout << "\n--- Estado da Lista ---\n";
                imprime(&minhaLista); // chama a função de imprimir
                cout << "-----------------------\n";
                break;

            case 0:
                cout << "Encerrando o programa... Ate logo!\n";
                break;

            default: // tratamento para caso o usuário digite '8', por exemplo
                cout << "[AVISO] Opcao invalida! Tente novamente.\n";
        }
    } while (opcao != 0);

    return 0; // encerra o código C++ com sucesso
}
