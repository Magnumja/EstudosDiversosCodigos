#include <iostream>
using namespace std;

#define MAX 100

struct REG {
    int chave;
};

struct STACK {
    REG vet[MAX];
    int topo;
};

// começa com pilha vazia
void criar(STACK *p){
    p->topo = -1;
}

// empilhar (colocar elemento)
bool empilhar(STACK *p, REG x){
    if(p->topo == MAX - 1){
        cout << "Cheia!" << endl;
        return false;
    }

    p->vet[++p->topo] = x; // já soma e insere
    return true;
}

// desempilhar (agora mostrando o que saiu)
bool desempilhar(STACK *p, REG *x){
    if(p->topo == -1){
        cout << "Vazia!" << endl;
        return false;
    }

    *x = p->vet[p->topo--]; // pega e já remove
    return true;
}

// só olhar o topo (sem mexer na pilha)
bool olharTopo(STACK *p, REG *x){
    if(p->topo == -1) return false;

    *x = p->vet[p->topo];
    return true;
}

// quantos elementos tem
int qtd(STACK *p){
    return p->topo + 1;
}

// limpa tudo
void limpar(STACK *p){
    p->topo = -1; // basicamente reseta tudo
}

// procurar valor
int procurar(STACK *p, int valor){
    int i = p->topo;

    // vou descendo até achar ou acabar
    while(i >= 0){
        if(p->vet[i].chave == valor)
            return i;
        i--;
    }

    return -1;
}

// mostrar pilha
void mostrar(STACK *p){
    if(p->topo < 0){
        cout << "Nada na pilha!" << endl;
        return;
    }

    cout << "[TOPO]" << endl;

    int i = p->topo;
    while(i >= 0){
        cout << p->vet[i].chave << endl;
        i--;
    }

    cout << "[BASE]" << endl;
}

int main(){
    STACK p;
    REG r, aux;

    criar(&p);

    // simulando uso (bem direto)
    r.chave = 5; empilhar(&p, r);
    r.chave = 15; empilhar(&p, r);
    r.chave = 25; empilhar(&p, r);

    mostrar(&p);

    desempilhar(&p, &aux);
    cout << "Saiu: " << aux.chave << endl;

    if(olharTopo(&p, &aux))
        cout << "Topo agora: " << aux.chave << endl;

    cout << "Total: " << qtd(&p) << endl;

    int pos = procurar(&p, 15);
    if(pos >= 0)
        cout << "Achei na pos: " << pos << endl;
    else
        cout << "Nao tem esse valor" << endl;

    limpar(&p);
    mostrar(&p);

    return 0;
}