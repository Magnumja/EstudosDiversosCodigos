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

int main()
{

    
    return 0;
}
