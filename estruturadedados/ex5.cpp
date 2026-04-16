#include <iostream>

using namespace std;
#define MAX 6

// Fila circular (alocação estática)
typedef int TIPOCHAVE;

// cria a estrutura
typedef struct{
    TIPOCHAVE chave;
    //nome
    //cpf
    //idade
}REGISTRO;

// cria a fila
typedef struct{
    REGISTRO A[MAX];
    // variáveis de controle
    int ini; // marcar a posição inicial
    int qtd; // quantidade de elementos
}FILA;

// Funções necessárias
void init(FILA *f);
int qtdElem(FILA *f);
void imprimir(FILA *f);
bool insereFila(FILA *f, REGISTRO reg);
bool removeFila(FILA *f);

int main()
{
    REGISTRO aux; // auxiliar para inserir
    bool r;       // resposta dos métodos
    FILA f;       // criação da nossa fila
    int opcao;    // variável para controlar a escolha do usuário

    // iniciar a manipulação
    init(&f);

    // Loop do Menu Interativo
    do {
        cout << "\n====== MENU DA FILA CIRCULAR ======\n";
        cout << "1. Inserir elemento\n";
        cout << "2. Remover elemento\n";
        cout << "3. Imprimir fila\n";
        cout << "4. Ver quantidade de elementos\n";
        cout << "0. Sair\n";
        cout << "Escolha uma opcao: ";
        cin >> opcao;

        switch(opcao) {
            case 1:
                cout << "Digite o valor (chave) a ser inserido: ";
                cin >> aux.chave;
                r = insereFila(&f, aux);
                
                // Validação de Inserção
                if (r == true) {
                    cout << "Elemento inserido na fila!\n";
                } else {
                    cout << "Fila cheia (Overflow)! Nao foi possivel inserir.\n";
                }
                break;

            case 2:
                r = removeFila(&f);
                
                // Validação de Remoção
                if (r == true) {
                    cout << "Elemento do inicio removido!\n";
                } else {
                    cout << "Fila vazia (Underflow)! Nao ha o que remover.\n";
                }
                break;

            case 3:
                cout << "Estado atual da Fila: ";
                imprimir(&f);
                break;
                
            case 4:
                cout << "Quantidade de elementos na fila: " << qtdElem(&f) << " de " << MAX << endl;
                break;

            case 0:
                cout << "Encerrando o programa...\n";
                break;

            default:
                cout << "Opcao invalida! Tente novamente.\n";
        }
    } while (opcao != 0);

    return 0;
}

// 1. passa por referência
void init(FILA *f){
    // inicializa a nossa fila
    f->ini = 0; // inicio na posição 0
    f->qtd = 0; // possui 0 elementos
}

// 2. retornar qtd
int qtdElem(FILA *f){
    // retorno quantos elementos a fila possui
    return f->qtd;
}

// 3. impressão
void imprimir(FILA *f){
    // Verifica se a fila está vazia antes de tentar imprimir
    if (f->qtd == 0) {
        cout << "Vazia." << endl;
        return;
    }
    
    // pegar a posição inicial
    int i = f->ini; // controla o inicio
    int j;
    for(j=0; j < f->qtd; j++){
        cout << f->A[i].chave << " ";
        // pulo do gato: avança circularmente
        i = (i + 1) % MAX;
    }
    cout<<endl;
}

// 4. insere
bool insereFila(FILA *f, REGISTRO reg){
    // REGRAS ANTES DE INSERIR
    // - se estiver cheia
    if (f->qtd >= MAX)
        return false;
        
    // calcula a posição para inserir
    int pos = (f->ini + f->qtd) % MAX;
    // insere o elemento
    f->A[pos] = reg;
    // atualiza a quantidade de elementos
    f->qtd++;
    return true;
}

// 5. remover
bool removeFila(FILA *f){
    // a fila é vazia??
    if (f->qtd == 0) 
        return false;

    // calcular o início
    f->ini = (f->ini + 1) % MAX;
    f->qtd--;
    return true;
}
