#include <iostream>

using namespace std;

void funcao(int *x, int *y){
    int aux = *x;
    *x = *y;
    *y = aux;
}

int main(){
    int x, y;

    cout << "Me fale o valor da variavel x e y: ";
    cin >> x >> y;

    cout << "Valor de x antes da troca: " << x << " e de y: " << y << "\n";

    funcao(&x, &y);

    cout << "Valor de x depois da troca: " << x << " e de y: " << y << "\n";

    return 0;
}
