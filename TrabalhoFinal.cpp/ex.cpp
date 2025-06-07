/*
Descrição do problema

Você foi contratado por uma agência espacial para desenvolver um sistema simples de gerenciamento de robôs.
Esse sistema deve ser capaz de:

1. Cadastrar até 4 robôs.
2. Listar os robôs cadastrados.
3. Simular uma missão baseada na energia dos robôs.
4. Exibir um "campo de missão" onde os robôs podem estar posicionados.
5. Recuperar robô.

Para representar o nosso Robô, crie a seguinte estrutura:

struct Robo {
    int identificador;
    char[50] nome;
    int energia;
    int nivel;
};
Funcionalidades obrigatórias
O sistema deve apresentar um menu com as opções:

1 - Cadastrar robô
2 - Listar robôs
3 - Simular missão
4 - Mostrar campo de missão
5 - Recuperar robô
6 - Sair

Cadastrar robô: Armazene os dados em um vetor de Robôs.
Listar robôs: Exiba os dados dos robôs.
Simular missão: Escolha um robô e remova ele da base, com base em sua energia mostrar o resultado:
Energia > 20: Sucesso, movimenta o robo no tabuleiro (de forma aleatória) e consome 20 de energia do robô
Energia < 20: Falha, não faz nada com o robô
Campo de missão: Crie uma matriz 2x2 (int campo[2][2]) para representar a posição dos robôs. Preencha com os identificadores dos robôs que estão no tabuleiro.
Recuperar robô: Escolha um robô e busque por ele no tabuleiro, depois remova ele do campo e volte para base.

*/

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

struct Robo {
    int identificador;
    char nome[50];
    int l, c; // posição no campo (-1 quando não está)
    int energia;
    int nivel;
};

void Cadastro(Robo cadastrarRobo[], int tamanho) {
    system("cls");
    cin.ignore();
    for (int i = 0; i < tamanho; i++) {
        cadastrarRobo[i].identificador = i;
        cadastrarRobo[i].l = -1; // Não está no campo ainda
        cadastrarRobo[i].c = -1;

        cout << "Identificador: " << cadastrarRobo[i].identificador << endl;
        cout << "Qual o nome do robo " << i + 1 << ": ";
        cin.getline(cadastrarRobo[i].nome, 50);
        cout << "Quantidade de energia do robo: ";
        cin >> cadastrarRobo[i].energia;
        cout << "Qual o nivel do robo: ";
        cin >> cadastrarRobo[i].nivel;
        cin.ignore();
        cout << endl;
    }
}

void Listar(Robo cadastrarRobo[], int tamanho) {
    system("cls");
    if (tamanho == 0) {
        cout << "Nenhum robo cadastrado ainda.\n";
        return;
    }

    for (int i = 0; i < tamanho; i++) {
        cout << "\nRobo " << i + 1 << ":\n";
        cout << "  Identificador: " << cadastrarRobo[i].identificador << endl;
        cout << "  Nome: " << cadastrarRobo[i].nome << endl;
        cout << "  Energia: " << cadastrarRobo[i].energia << endl;
        cout << "  Nivel: " << cadastrarRobo[i].nivel << endl;
        if (cadastrarRobo[i].l != -1 && cadastrarRobo[i].c != -1)
            cout << "  Posicao no campo: [" << cadastrarRobo[i].l << "][" << cadastrarRobo[i].c << "]\n";
        else
            cout << "  Posicao no campo: Base\n";
    }
}

void Tabuleiro(Robo cadastrarRobo[], int campo[2][2], int tamanho) {
    system("cls");
    // Atualiza campo com os robos que estao no tabuleiro
    for (int l = 0; l < 2; l++) {
        for (int c = 0; c < 2; c++) {
            campo[l][c] = -1; // reset campo
        }
    }

    for (int i = 0; i < tamanho; i++) {
        if (cadastrarRobo[i].l != -1 && cadastrarRobo[i].c != -1) {
            campo[cadastrarRobo[i].l][cadastrarRobo[i].c] = cadastrarRobo[i].identificador;
        }
    }

    cout << "Campo de missao (2x2):\n";
    for (int l = 0; l < 2; l++) {
        for (int c = 0; c < 2; c++) {
            if (campo[l][c] == -1)
                cout << "[   ] ";
            else
                cout << "[" << campo[l][c] << "] ";
        }
        cout << endl;
    }
}

void SimularMissao(Robo cadastrarRobo[], int campo[2][2], int tamanho) {
    system("cls");
    int numero_robo;
    cout << "Digite o identificador do robo para a missao: ";
    cin >> numero_robo;

    if (numero_robo < 0 || numero_robo >= tamanho) {
        cout << "Identificador invalido!\n";
        return;
    }

    if (cadastrarRobo[numero_robo].energia > 20) {
        srand(time(NULL));
        int l, c;
        // tentar posicionar em posicao aleatoria livre
        int tentativas = 0;
        do {
            l = rand() % 2;
            c = rand() % 2;
            tentativas++;
            if (tentativas > 10) {
                cout << "Nao ha posicao livre no campo para o robo.\n";
                return;
            }
        } while (campo[l][c] != -1);

        campo[l][c] = numero_robo;
        cadastrarRobo[numero_robo].energia -= 20;
        cadastrarRobo[numero_robo].l = l;
        cadastrarRobo[numero_robo].c = c;

        cout << "Missao realizada com sucesso! Robo movido para a posicao [" << l << "][" << c << "].\n";
        cout << "Energia restante: " << cadastrarRobo[numero_robo].energia << endl;
    } else {
        cout << "Energia insuficiente! Necessario mais que 20 para a missao.\n";
    }
}

void RecuperarRobo(Robo cadastrarRobo[], int campo[2][2], int tamanho) {
    system("cls");
    int id;
    cout << "Digite o identificador do robo a ser recuperado: ";
    cin >> id;

    if (id < 0 || id >= tamanho) {
        cout << "Identificador invalido!\n";
        return;
    }

    bool encontrado = false;

    for (int l = 0; l < 2; l++) {
        for (int c = 0; c < 2; c++) {
            if (campo[l][c] == id) {
                campo[l][c] = -1;
                cadastrarRobo[id].l = -1;
                cadastrarRobo[id].c = -1;
                encontrado = true;
                cout << "Robo " << id << " recuperado da posicao [" << l << "][" << c << "] com sucesso!\n";
                break;
            }
        }
        if (encontrado) break;
    }

    if (!encontrado) {
        cout << "Robo " << id << " nao esta em missao no campo.\n";
    }
}

int main() {
    Robo cadastrarRobo[4];
    int campo[2][2];
    int tamanho = 0;
    int op;

    // Inicializa campo como vazio (-1)
    for (int l = 0; l < 2; l++) {
        for (int c = 0; c < 2; c++) {
            campo[l][c] = -1;
        }
    }

    do {
        cout << "\n--- Sistema de Gerenciamento de Robos ---\n";
        cout << "1 - Cadastrar robo\n";
        cout << "2 - Listar robos\n";
        cout << "3 - Simular missao\n";
        cout << "4 - Mostrar campo de missao\n";
        cout << "5 - Recuperar robo\n";
        cout << "6 - Sair\n";
        cout << "Escolha uma opcao: ";
        cin >> op;
        system("cls");

        switch (op) {
            case 1:
                if (tamanho >= 4) {
                    cout << "Limite maximo de robos (4) ja cadastrado.\n";
                } else {
                    int qtd;
                    cout << "Quantos robos quer cadastrar (max 4): ";
                    cin >> qtd;
                    if (qtd + tamanho > 4) {
                        cout << "Nao pode cadastrar mais que 4 robos no total.\n";
                    } else {
                        Cadastro(cadastrarRobo + tamanho, qtd);
                        tamanho += qtd;
                    }
                }
                break;
            case 2:
                Listar(cadastrarRobo, tamanho);
                break;
            case 3:
                SimularMissao(cadastrarRobo, campo, tamanho);
                break;
            case 4:
                Tabuleiro(cadastrarRobo, campo, tamanho);
                break;
            case 5:
                RecuperarRobo(cadastrarRobo, campo, tamanho);
                break;
            case 6:
                cout << "Saindo do programa.\n";
                break;
            default:
                cout << "Opcao invalida!\n";
                
                break;
        }
    } while (op != 6);

    return 0;
}
