#include <iostream>
#include <time.h>


/*Utilizando ponteiros faça um programa que:
a- Preencha um vetor com valores inteiros e aleatórios.
b- Mostre o conteúdo do vetor.
c- Mostre o endereço de cada posição do vetor.*/


using namespace std;

int main()
{
    int tam;

    cout << "Me fale o tamanho do vetor que deseja ser preenchido: ";
    cin >> tam;

    int* vet = new int[tam];

    // int vet[10]


    srand(time(NULL));
    for (int* ptr = vet; ptr < vet + tam; ptr++) {
        *ptr = rand() % 100;
    }

    cout << "O vetor gerado: ";
    for(int* ptr = vet; ptr < vet + tam; ptr++){
        cout << *ptr << " | ";
    }
    cout << "O vetor gerado: ";
    for(int* ptr = vet; ptr < vet + tam; ptr++){
        cout << ptr << " | ";
    }


    delete[] vet;
    return 0;
}
