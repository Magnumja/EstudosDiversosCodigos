#include <iostream>

using namespace std;
void insereordenado(int vet(), int &qtd_elem, int num);
int TAM = 10;
int main()
{
    int vet[TAM] = (1,3,5,7,9);
    int qt_elem = 5;
    cout << "Valor a inserir no vetor: ";
    cin >> num;
    insereordenado(vet, qtd_elem, num);
    return 0;
    
}

void insereordenado(int vet(), int qtd_elem, int num){
    if (qtd_elem >= TAM)
    {
        cout << "Capacidade excedida! \n";
        return;
    }
    int i = qtd_elem - 1;

    while (i>=0 && vet[i]>num)
    {
        vet[i+1]=vet[i];
        i--;
    }
    vet[i+1] = num;

}