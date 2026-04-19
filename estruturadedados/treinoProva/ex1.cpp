#include <iostream>


using namespace std;


// funcao antes da main

void trocaValores(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;

}


int main(){
    int a = 5;
    int b = 10;


    cout << "Antes da troca de valores: a = " << a << ", b = " << b << endl;


    trocaValores(&a, &b);

    cout << "Depois da troca de valores a = " << a << ", b = " << b << endl;

    return 0;

}