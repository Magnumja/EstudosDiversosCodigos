/*Faça um programa que tenha um procedimento para exibir a tabuada de um número. 
A saída deve seguir o seguinte formato:
1 x N =
2 x N =
3 x N =
*/

#include <iostream>

using namespace std;

void Tabuada(int num, int resultado){
    for (int i = 1; i < 11; i++)
    {
        resultado = i*num;
        cout << i << "x" << num << " = " << resultado << "\n";
    }
    
}

int main(){
    int num, resultado;

    cout << "Digite o numero que deseja saber a tabuada: ";
    cin >> num;
    cout << "\n" << endl;

    Tabuada(num, resultado);
    return 0;
}