/*
Utilize o operador new() para alocar um bloco com 5 números inteiros.
a) Preencha este bloco com valores inteiros.
b) Mostre os dados preenchidos.
c) Após o uso libere a memória por meio do operador delete()
*/

#include <iostream>
#include <stdio.h> //para funcao gets
#include <stdlib.h> //para funcao malloc

using namespace std;


int main(){

    //char *vnome;
    //vnome = (char *)malloc(sizeof(char)); //o que coloca dentro do malloc eh o tamanho do tipo de dados que quer alocar
    // gets(vnome);
    //cout << vnome;

    int* p= new int[5];

    for (int i = 0; i < 5; i++)
    {
        cout << "Digite o valor do " << i+1 << " inteiro que deseja guardar: ";
        cin >> p[i];
    }

    for (int i = 0; i < 5; i++)
    {
        cout << p[i];
    }



    delete[] p;

    return 0;
}