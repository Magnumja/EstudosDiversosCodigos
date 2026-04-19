#include <iostream>

using namespace std;

#define MAX 100 // Tamanho máximo da nossa pilha na memória

// 1. O REGISTRO: É o "molde" do dado que vamos guardar
typedef int TIPOCHAVE; // Apenas um apelido para 'int'. Facilita se quisermos mudar para 'float' depois.

typedef struct {
    TIPOCHAVE chave; // Aqui fica o valor real (ex: ID do cliente, senha, etc.)
} REGISTRO;

// 2. A PILHA: A estrutura que gerencia a memória
typedef struct {
    REGISTRO A[MAX]; // Um vetor comum. É aqui que os dados ficam armazenados fisicamente.
    int top;         // A nossa variável mais importante! Ela diz em qual "degrau" da pilha estamos.
} PILHA;

// Protótipos: Avisando o compilador que essas funções existem
void initPilha(PILHA *p); 
void exibePilha(PILHA *p); 
bool push(PILHA *p, REGISTRO reg); 
bool pop(PILHA *p); 

int main() {
    REGISTRO aux; // Uma caixinha temporária para guardar o dado digitado pelo usuário
    PILHA pilha;  // Aqui a pilha nasce de verdade na memória!

    // Passamos o ENDEREÇO da pilha (&) para que a função possa alterá-la de verdade
    initPilha(&pilha); 

    int op = -1;
    bool resp;

    while (op != 0) {
        cout << "\n--- MENU HELP DESK ---" << endl;
        cout << "0 - Sair" << endl;
        cout << "1 - Inicializar pilha (Zerar)" << endl;
        cout << "2 - Inserir Elemento (Push)" << endl;
        cout << "3 - Remover Elemento (Pop)" << endl;
        cout << "4 - Exibir pilha" << endl;
        cout << "Opcao: ";
        cin >> op;

        switch (op) {
            case 0:
                cout << "Fim do programa!!" << endl;
                break;
            case 1:
                initPilha(&pilha);
                cout << "Pilha inicializada/zerada!!" << endl;
                break;
            case 2:
                cout << "Digite a chave do cliente: ";
                cin >> aux.chave; // Guarda o valor na struct auxiliar
                
                resp = push(&pilha, aux); // Manda o endereço da pilha e a struct com o dado
                if (resp) cout << "Elemento inserido com sucesso!" << endl;
                break;
            case 3:
                resp = pop(&pilha);
                if (resp) cout << "Elemento removido com sucesso!" << endl;
                break;
            case 4:
                exibePilha(&pilha);
                break;
            default:
                cout << "Opcao invalida" << endl;
        }
    }
    return 0;
}

// ---------------- IMPLEMENTAÇÃO DAS FUNÇÕES ----------------

// Inicializa a pilha colocando o topo em -1 (posição inválida no vetor = vazio)
// Como recebemos um ponteiro (*p), usamos a setinha (->) para acessar o que tem dentro da struct
void initPilha(PILHA *p) {
    p->top = -1; 
}

// Função PUSH: Entra dado
bool push(PILHA *p, REGISTRO reg) {
    // 1º passo: A pilha está cheia? (O vetor vai até MAX-1, ou seja, 99)
    if (p->top >= MAX - 1) {
        cout << "Erro: pilha cheia!" << endl;
        return false;
    }
    
    // 2º passo: Sobe um degrau
    p->top = p->top + 1; 
    
    // 3º passo: Guarda o registro no novo topo do vetor
    p->A[p->top] = reg; 
    return true;
}

// Função POP: Sai dado
bool pop(PILHA *p) {
    // 1º passo: A pilha está vazia? (topo é -1?)
    if (p->top == -1) {
        cout << "Erro: pilha vazia!" << endl;
        return false;
    }
    
    // 2º passo: Desce um degrau. 
    // Nota do professor: O dado antigo CONTINUA na memória do vetor, mas nós o ignoramos.
    // Ele será esmagado no próximo Push.
    p->top = p->top - 1; 
    return true;
}

// Imprime do topo até a base
void exibePilha(PILHA *p) {
    cout << "\nTopo ->" << endl;
    // O laço começa no 'top' atual e vai descendo até o índice 0 (base)
    for (int i = p->top; i >= 0; i--) {
        cout << "\t[ " << p->A[i].chave << " ]" << endl;
    }
    cout << "\t<- Base\n" << endl;
}
