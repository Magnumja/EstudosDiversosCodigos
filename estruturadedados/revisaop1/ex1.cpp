/*
1)  Você  trabalha  em  um  helpdesk  de  suporte  técnico,  onde  as  solicitações  de
atendimento  dos  clientes  são gerenciadas por uma estrutura de dados. Cada cliente é
cadastrado por meio de uma senha e esta é utilizada para sua identificação.
A sequência de solicitações e atendimentos da equipe do helpdesk é a seguinte:
1.  O cliente 6 solicita ajuda.
2.  O cliente 7 solicita ajuda.
3.  O cliente 8 solicita ajuda.
4.  O cliente 9 solicita ajuda.
5.  A equipe do helpdesk atende e finaliza a chamada.
6.  O cliente 13 solicita ajuda.
7.  O cliente 15 solicita ajuda.
8.  A equipe do helpdesk atende e finaliza a chamada.
9.  A equipe do helpdesk atende e finaliza a chamada.
10. A equipe do helpdesk atende e finaliza a chamada.

Considere que inicialmente não havia nenhum chamado, a estrutura estava vazia. Com
base na sequência apresentada responda às seguintes questões:
a)  Caso a estrutura fosse uma pilha. Ainda há clientes para serem atendidos? Se
sim qual a ordem na pilha dos clientes?

b)  Caso a estrutura fosse uma fila. Ainda haveria clientes para serem atendidos? Se
sim qual a ordem na fila para atendimento?
*/

/*

a) [6,7,8,9] -> atende -> [6,7,8,13,15] - > atende  -> [6,7] -> finaliza o a
tendimento com 2 ainda para serem atendidos,
se for atendido agora seria primeior o 7 e depois o 6, respeitando a lei de pilha
LIFO (Last In First Out), ultimo que entra primeiro que sai


b) ORDEM DA FILA -> FIFO (first in first out)
[6,7,8,9] -> atende -> [7,8,9] -> [7,8,9,13,15] -> atende3x -> [13,15]
Sim, ainda haveria clientes. A ordem na fila para atendimento é: 13
(frente da fila, próximo a ser atendido) e 15 (fundo da fila).




*/

#include <iostream>
#include <cstdlib>
#include <stdlib.h>

using namespace std;

#define MAX 100
// 1. O REGISTRO: É o "molde" do dado que vamos guardar
typedef int TIPOCHAVE;

typedef struct{    
    TIPOCHAVE chave;
}REGISTRO;

// 2, pilha a estrutura que gerencia a memoria

typedef struct{
    REGISTRO A[MAX];
    int top; // A nossa variável mais importante! Ela diz em qual "degrau" da pilha estamos.
}PILHA;


//Prototipos, avisando ao complicador q essas funcoes existem

void initPilha(PILHA *p);
void exibePilha(PILHA *p);
void pushPilha(PILHA *p);
void popPilha(PILHA *p);

int main()
{
    REGISTRO aux; // uma caixinha temporaria para guardar i dadi digitado pelo usuario
    PILHA pilha; // Aqui a pilha nasce de verdade na memoria

    // Passamos o endereco da pilha(&) para que a funcao possa alterala de verdade

    initPilha(&Pilha);

    int op = -1;
    bool resp;

    while(op != 0){

        cout << " Bem vindo ao HELPDESK selecione o que deseja " << endl;
        cout << " 0 - Sair" << endl;
        cout << " 1 - Abrir ticket e aguarde operacao (inserir)" << endl;
        cout << " 2 - Remover Elemento (Pop)" << endl;
        cout << " 3 - Exibir pilha" << endl;

        cout << " opcao: ";
        cin >> op;

        switch(op) {

            case 0: 
                cout << "Fim do atendimento." << endl;
                break;
            case 1;
                cout << "Qual seu id da empresa: ";
                cin >> aux.chave; // guarda o valor na struct auxiliar

                resp = push(&pilha, aux); //Manda o endereço da pilha e a struct com o dado
                if(resp) cout << "Ticket gerado com sucesso!" << endl 
                break;
            case 2:
                resp = pop(&pilha);
                if(resp) cout << "Elemento inserido com sucesso!" << endl;
                break;
            case 3:
                exibePilha(&pilha);
                break;
            default:
                cout << "Opcao invalida" << endl;
        }             
    return 0;
}


