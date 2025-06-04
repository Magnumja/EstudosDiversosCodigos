#include <iostream>

using namespace std;

int main()
{
    double Notas[10];
    int posicao;
    double menor, aux;
    bool troca;

    // Entrada de notas
    for (int i = 0; i < 10; i++)
    {
        cout << "Digite a " << i + 1 << "ª nota: ";
        cin >> Notas[i];
    }

    system("cls"); 

    
    for (int j = 0; j < 9; j++) 
    {
        menor = Notas[j]; 
        posicao = j;
        troca = false;

        for (int k = j + 1; k < 10; k++) 
        {                                
            if (Notas[k] < menor)
            {
                menor = Notas[k];
                posicao = k;
                troca = true;
            }
        }

        if (troca) 
        {
            aux = Notas[j];
            Notas[j] = menor;
            Notas[posicao] = aux;
        }
    }

    // Exibe as notas ordenadas
    for (int m = 0; m < 10; m++)
    {
        cout << " | " << Notas[m];
    }

    return 0;
}
