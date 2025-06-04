#include <iostream>
using namespace std;

int bubble_sort(int vetor[], int tamanho)
{
    if (tamanho == 1)
    {
        return 1;
    }

    for (int i = 0; i < tamanho; i++)
    {
        if (vetor[i] > vetor[i + 1])
        {
            int temp = vetor[i];
            vetor[i] = vetor[i + 1];
            vetor[i + 1] = temp;
        }
    }

    bubble_sort(vetor, tamanho - 1);
}

int main()
{
    int vetor[6] = {2, 8, 1, 9, 5, 3};
    int tamanho = 6;
    bubble_sort(vetor, tamanho - 1);
    cout << "Vetor ordenado:" << endl;
    for (int i = 0; i < tamanho; i++)
        cout << vetor[i] << ", ";

    cout << endl;
}