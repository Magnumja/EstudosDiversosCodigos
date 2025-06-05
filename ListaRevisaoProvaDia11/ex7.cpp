/*
Em um sistema para auxiliar na automatização de pedidos, um dos módulos do sistema é
responsável por cadastrar os pratos servidos no restaurante. De acordo com a estrutura de
dados apresentada crie uma função “CadastraPrato” que dado um ponteiro insira um novo
registro nesta estrutura. Para a solução utilize um vetor de registos com no máximo 10
elementos.


Estrutura de dados:
struct Prato {
    int id;
    char nome[50];
    char descricao[100];
    float preco;
    int quantidade_vendas;
};
*/

#include <iostream>

using namespace std;

struct Prato
{
    int id;
    char nome[50];
    char descricao[100];
    float preco;
    int quantidade_vendas;
};

void CadastrarPrato(Prato p[], int tamanho)
{

    if (tamanho > 10)
    {
        cout << "Tamanho invalido, tente um numero ate 10";
    }
    cin.ignore();
    if (tamanho <= 10)
    {
        for (int i = 0; i < tamanho; i++)
        {

            p[i].id = i + 1;
            cout << (p + i)->id << " id \n";
            cout << "Cadastre o nome do " << i + 1 << " prato: ";
            cin.getline((p + i)->nome, 50);
            cout << "Descricao do prato: ";
            cin.getline((p + i)->descricao, 100);
            cout << "Preco: ";
            cin >> (p + i)->preco;
            cout << "Quantidade de vendas: ";
            cin >> (p + i)->quantidade_vendas;
            system("cls");
        }
    }
}

void Exibir(Prato p[], int tamanho)
{
    for (int i = 0; i < tamanho; i++)
    {
        cout << i + 1 << " prato tem nome " << p[i].nome << " com descricao ' " << p[i].descricao << " ' preco " << p[i].preco << " com uma quantidade de vemdas de " << p[i].quantidade_vendas;
        cout << "\n";
    }
}

int main()
{
    int tamanho;
    Prato pratos[10];
    Prato *p = pratos;

    cout << "Seja bem vindo ao gerenciamento do restaurante, abaixo segue o que for pedido: \n";
    cout << "Quantos pratos deseja registrar: ";
    cin >> tamanho;

    CadastrarPrato(pratos, tamanho);

    Exibir(pratos, tamanho);

    return 0;
}
