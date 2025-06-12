/*
Utilizando ponteiros e alocação dinâmica de memória faça um programa que:
a. Crie uma struct (registro) para armazenar dados referentes aos produtos em
estoque.
struct produto{
char nome[30];
float preco;
int codigo;
};
b. Solicite ao usuário a quantidade de dados a serem tratados. Nesta etapa aloque
dinamicamente um vetor com a quantidade de dados requisitada.
c. Verifique se a quantidade de memória pode ser alocada corretamente e, caso
não seja possível, finalize o programa. Nesta etapa verifique se o ponteiro para
manipulação do bloco é válido. Caso seja inválido finalizar o programa.
d. Utilize uma estrutura de repetição “for” e a quantidade de informações a serem
tratadas para preencher o bloco de memória por meio do teclado. Informe nome,
preço e código de cada produto.
e. Faça um laço “for” para mostrar todos os dados armazenados (nome, preço e
codigo).
f. No final do programa utilize o comando apropriado para liberar o espaço de
memória alocado dinamicamente.
*/

#include <iostream>
using namespace std;

struct produto
{
    char nome[30];
    float preco;
    int codigo;
};

int main()
{

    int tam;

    cout << "Por favor me diga quantos dados deseja registrar: ";
    cin >> tam;
    produto *ptr = new produto[tam];

    if(ptr == NULL)
    {
       cout << "Erro ao alocar memoria!" << endl;
       return EXIT_FAILURE;
    }

    for (int i = 0; i < tam; i++)
    {
        cout << "Digite o codigo:";
        cin >> (ptr+i)->codigo;
        cout << "Digite o nome do produto: ";
        cin >> (ptr+i)->nome;
        cout << "Digite o preco do produto: ";
        cin >> (ptr+i)->preco;
    }


    for (int i = 0; i < tam; i++)
    {
        cout << "\n---------------------\n";
        cout << "Codigo: " << (ptr+i)->codigo;
        cout << "\nNome: " << (ptr+i)->nome;
        cout << "\nPreco: " << (ptr+i)->preco;
        cout << "\n---------------------\n";
        cout << "\n";
    }

    



    delete[] ptr;
    
    

    return 0;
}
