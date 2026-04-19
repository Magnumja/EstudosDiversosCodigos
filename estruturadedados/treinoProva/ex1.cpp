#include <iostream>
#include <cstdlib> // Necessário para a função system()

using namespace std;

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

    cout << "Depois da troca de valores: a = " << a << ", b = " << b << endl;

    // Esta linha manterá o terminal aberto para você ler o resultado
    system("pause"); 

    return 0;
}