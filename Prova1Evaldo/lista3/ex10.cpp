/* Converter número para binário:
Escreva uma função recursiva para converter
um número decimal em binário.*/

#include <iostream>
using namespace std;

void paraBinario(int n) {
    if (n == 0) {
        cout << 0;
        return;
    }

    if (n > 1) {
        paraBinario(n / 2);
    }
    cout << n % 2;
}

int main() {
    int numero;

    cout << "Digite um número decimal: ";
    cin >> numero;

    cout << "Binário: ";
    paraBinario(numero);
    cout << endl;

    return 0;
}
