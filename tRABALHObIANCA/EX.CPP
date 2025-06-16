#include <iostream>
#include <string>
using namespace std;

// 1. Fatorial
int fatorial(int n) {
    if (n <= 1) return 1;
    return n * fatorial(n - 1);
}

// 2. Fibonacci
int fibonacci(int n) {
    if (n <= 1) return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

// 3. Soma da lista
int somaLista(int lista[], int tamanho, int i = 0) {
    if (i == tamanho) return 0;
    return lista[i] + somaLista(lista, tamanho, i + 1);
}

// 4. Contar elementos
int contarElementos(int lista[], int tamanho, int i = 0) {
    if (i == tamanho) return 0;
    return 1 + contarElementos(lista, tamanho, i + 1);
}

// 5. Buscar número
bool buscarNumero(int lista[], int tamanho, int alvo, int i = 0) {
    if (i == tamanho) return false;
    if (lista[i] == alvo) return true;
    return buscarNumero(lista, tamanho, alvo, i + 1);
}

// 6. Inverter string
string inverterString(string str) {
    if (str.empty()) return "";
    return inverterString(str.substr(1)) + str[0];
}

// 7. Verificar palíndromo
bool ehPalindromo(string palavra, int inicio = 0, int fim = -1) {
    if (fim == -1) fim = palavra.length() - 1;
    if (inicio >= fim) return true;
    if (palavra[inicio] != palavra[fim]) return false;
    return ehPalindromo(palavra, inicio + 1, fim - 1);
}

// 8. Imprimir lista reversa
void imprimirReverso(int lista[], int tamanho, int i = 0) {
    if (i == tamanho) return;
    imprimirReverso(lista, tamanho, i + 1);
    cout << lista[i] << " ";
}

// 9. Maior número da lista
int maiorNumero(int lista[], int tamanho, int i = 0) {
    if (i == tamanho - 1) return lista[i];
    int maiorResto = maiorNumero(lista, tamanho, i + 1);
    return (lista[i] > maiorResto) ? lista[i] : maiorResto;
}

// 10. Converter decimal para binário
string paraBinario(int n) {
    if (n == 0) return "";
    return paraBinario(n / 2) + to_string(n % 2);
}

int main() {
    int opcao;
    int lista[] = {3, 5, 7, 2, 8};
    int tamanho = sizeof(lista) / sizeof(lista[0]);

    cout << "Escolha uma opção:\n";
    cout << "1 - Fatorial\n";
    cout << "2 - Fibonacci\n";
    cout << "3 - Soma da lista\n";
    cout << "4 - Contar elementos da lista\n";
    cout << "5 - Buscar número na lista\n";
    cout << "6 - Inverter string\n";
    cout << "7 - Verificar palíndromo\n";
    cout << "8 - Imprimir lista reversa\n";
    cout << "9 - Maior número na lista\n";
    cout << "10 - Converter para binário\n";
    cout << "Opção: ";
    cin >> opcao;

    switch (opcao) {
        case 1: {
            int n;
            cout << "Digite um número: ";
            cin >> n;
            cout << "Fatorial: " << fatorial(n) << endl;
            break;
        }
        case 2: {
            int n;
            cout << "Digite a posição de Fibonacci: ";
            cin >> n;
            cout << "Fibonacci: " << fibonacci(n) << endl;
            break;
        }
        case 3:
            cout << "Soma da lista: " << somaLista(lista, tamanho) << endl;
            break;
        case 4:
            cout << "Total de elementos: " << contarElementos(lista, tamanho) << endl;
            break;
        case 5: {
            int alvo;
            cout << "Digite o número a buscar: ";
            cin >> alvo;
            cout << (buscarNumero(lista, tamanho, alvo) ? "Número encontrado!" : "Número não encontrado.") << endl;
            break;
        }
        case 6: {
            string str;
            cout << "Digite a string: ";
            cin >> str;
            cout << "Invertida: " << inverterString(str) << endl;
            break;
        }
        case 7: {
            string palavra;
            cout << "Digite a palavra: ";
            cin >> palavra;
            cout << (ehPalindromo(palavra) ? "É palíndromo!" : "Não é palíndromo.") << endl;
            break;
        }
        case 8:
            cout << "Lista reversa: ";
            imprimirReverso(lista, tamanho);
            cout << endl;
            break;
        case 9:
            cout << "Maior número da lista: " << maiorNumero(lista, tamanho) << endl;
            break;
        case 10: {
            int n;
            cout << "Digite um número: ";
            cin >> n;
            string bin = paraBinario(n);
            cout << "Binário: " << (bin.empty() ? "0" : bin) << endl;
            break;
        }
        default:
            cout << "Opção inválida." << endl;
    }

    return 0;
}
