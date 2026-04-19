#include <iostream> // para utilizar cin e cout

using namespace std; // apelido std

// definir um apelido para o tipo int
typedef int TIPOCHAVE;
#define MAX 100

// Estrutura que representar um registro
typedef struct {
    TIPOCHAVE chave;
    // float altura
    // float peso
    // .....
}REGISTRO;

// Estrutura que representa a pilha
typedef struct {
    REGISTRO A[MAX]; //vetor est�tico tamanho 100
    int top; // vari�vel de controle da pilha
}PILHA;

// prot�tipos das fun��es/procedimentos
void initPilha(PILHA *p); // inicializa pilha
void exibePilha(PILHA *p); // exibir a pilha
bool push(PILHA *p, REGISTRO reg); // insere na pilha
bool pop(PILHA *p); // remover elemnto na pilha

int main()
{
    REGISTRO aux; // auxiliar na cria��o de registros
    PILHA pilha; // pilha principal

    initPilha(&pilha); // inicializa��o da pilha
    int op = -1; // controle do meu menu
    bool resp; // retorno das fun��es/procedimentos
    // menu de op��es
    while (op != 0){
        cout << "0 - Sair" << endl;
        cout << "1 - Inicializar pilha" << endl;
        cout << "2 - Inserir Elemento (push)" << endl;
        cout << "3 - Remover Elemento (pop)" << endl;
        cout << "4 - Exibir pilha" << endl;
        cout << "Opcao: ";
        cin >> op;

        switch (op) {
            case 0:
                cout << "Fim do programa!!" << endl;
                break;
            case 1:
                initPilha(&pilha);
                cout << "Pilha inicilizada!!" << endl;
                break;
            case 2:
                cout << "Digite a chave: ";
                cin >> aux.chave;

                resp = push(&pilha, aux);
                if (resp)
                    cout << "Elemento inserido com sucesso!" <<endl;
                else
                    cout << "N�o foi possivel inserir!" << endl;
                break;
            case 3:
                resp = pop(&pilha);
                if (resp)
                    cout << "Elemento removido com sucesso!" <<endl;
                else
                    cout << "N�o foi possivel remover!" << endl;
                break;
            case 4:
                exibePilha(&pilha);
                break;

            default:
                cout << "Opcao invalida" << endl;
        }
    }

    /*cout << "Topo da pilha: " << pilha.top << endl;

    aux.chave = 10; // primeiro valor para a pilha
    push(&pilha, aux);
    aux.chave = 20; // segundo valor para a pilha
    push(&pilha, aux);
    aux.chave = 30; // terceiro valor para a pilha
    push(&pilha, aux);

    cout << "Antes do pop:" << endl;
    exibePilha(&pilha); // exibir a nossa pilha

    pop(&pilha);

    cout << "Depois do pop:" << endl;
    exibePilha(&pilha); // exibir a pilha
    */
    return 0;
}
// inicializa a pilha com a vari�vel de controle em -1
void initPilha(PILHA *p)
{
    p->top = -1;
}
// exibi��o da pilha
void exibePilha(PILHA *p)
{
    cout << "Topo ->" << endl;

    for (int i = p->top; i >= 0; i--) {
        cout << "\t" << p->A[i].chave << endl;
    }

    cout << "\t<- Base" << endl;
}
// inser��o na pilha
bool push(PILHA *p, REGISTRO reg)
{
    // verificar se a nossa pilha est� CHEIA
    if (p->top >= MAX - 1) {
        cout << "Erro: pilha cheia!" << endl;
        return false;
    }
    // atualiza a nossa vari�vel de controle
    p->top = p->top + 1;
    // insere registro no vetor
    p->A[p->top] = reg;
    return true;
}
// remo��o de elemento da pilha
bool pop(PILHA *p)
{
    if (p->top == -1) {
        cout << "Erro: pilha vazia!" << endl;
        return false;
    }
    p->top = p->top - 1; // atualiza a vari�vel de controle
    return true;
}



