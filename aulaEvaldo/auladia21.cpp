#include <iostream>
#define TAM 5

using namespace std;

void troca(int v[], int indm, int i){
    int aux = v[i];
    v[i] = v[indm];
    v[indm] = aux;
};
int main()
{
    int v[TAM] = {50, 20, 40, 80, 30};

    int i, k, aux;
    int j;
    int indm;
    for (i = 0; i < TAM - 1; i++)
    {

        indm = i;

        for (j = i + 1; j < TAM; j++)
        {
            if (v[j] < v[indm])
            {
                indm = j;
            }
        }

        troca(v, indm, i);

        for (k = 0; k < TAM; k++)
        {
            cout << v[k] << " ";
        }
        cout << endl;
    }

    return 0;
}