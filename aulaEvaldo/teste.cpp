#include <iostream>
using namespace std;

bool encontra_numer(int lista[], int numero, int inicio, int fim) {
    if(inicio > fim) {
        return false;
    }
    if(inicio == fim) {
        return lista[inicio] == numero;
    }

    int tamanho = fim - inicio;
    int meio = tamanho / 2;

    return encontra_numer(lista, numero, inicio, inicio+meio) ||
           encontra_numer(lista, numero, inicio+meio+1, fim);
}

int main() {
    int lista[] = {1,2,3,4,5,6,7,8};
    int numero_busca = 1;

    int tamanho = (sizeof(lista) / sizeof(lista[0])) - 1;
    cout << tamanho;
    bool encontrou = encontra_numer(lista, numero_busca, 0, tamanho);

    if(encontrou) {
        cout << "Encontrou o numero";
    } else {
        cout << "Nao encontrou";
    }

}
