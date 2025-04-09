#include <iostream>
using namespace std;

int seEstar(int numeros[], int tamanho, int numeroDesejado)
{
   
    for (int i = 0; i < tamanho; i++)
    {
      if (numeros[i] == numeroDesejado)
      {
        return 1;
      }
      
    }

    return 0;
    
}

int main()
{
    int numeros[100];
    int entrada;
    int contador = 0;
    cout << "Me diga os numeros da sua lista(Digite -1 para fechar): \n";

    while (1)
    {
        cin >> entrada;
        if (entrada == -1)
            break;

        numeros[contador] = entrada;
        contador++;
    }

    int numeroDesejado;
    cout << "Me fale o numero que deseja saber se esta na lista \n";
    cin >> numeroDesejado;
    int resultado = seEstar(numeros, contador, numeroDesejado);

    if (resultado == 1)
    {
        cout << "O numero desejado esta sim na lista." << endl;
    }
    else
    {
    cout << "O numero desejado nao esta na lista." << endl;
        
    }

    return 0;
}