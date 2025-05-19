#include <iostream>

using namespace std;

bool numerosDiferentes(float a, float b) {
    return a != b;
}

int main() {
    float num1, num2;

    do {
        cout << "Digite dois numeros diferentes: ";
        cin >> num1 >> num2;

        if (!numerosDiferentes(num1, num2)) {
            cout << "Os numeros nao podem ser iguais. Tente novamente!\n";
        }
    } while (!numerosDiferentes(num1, num2));

    float soma = num1 + num2;
    float subtracao = num1 - num2;

    cout << "Soma: " << soma << "\n";
    cout << "Subtracao: " << subtracao << "\n";

    if (num1 == 0 || num2 == 0) {
        cout << "Divisao por zero nao permitida.\n";
    } else {
    // Usamos o operador ternário abaixo, que segue a estrutura:
    // (condição) ? valor_se_verdadeiro : valor_se_falso;
    //
    // No nosso caso:
    // Se num1 for maior que num2, então divisao = num1 / num2
    // Caso contrário, divisao = num2 / num1

    float divisao = (num1 > num2) ? num1 / num2 : num2 / num1;

    // Exibe o resultado da divisão
    cout << "Divisao: " << divisao << "\n";
}


    return 0;
}
