/*Verificar se uma palavra é um palíndromo: 
Crie uma função recursiva para verificar se 
uma palavra é um palíndromo (ex: "arara" é um palíndromo).*/


#include <iostream>
#include <string.h>

using namespace std;

string inverter(string texto, int i){
    if (i < 0)
    {
        return ""; 
    }
    else
    {
        return string(1, texto[i]) + inverter(texto, i-1); // Transforma char em string
    }
}

int main(){

    string texto;

    cout << "Me fale uma string e eu te darei o contrario dela: ";
    cin >> texto;

    string resultado = inverter(texto, texto.length() - 1);

    cout << "String invertida: " << resultado << endl;


    if (texto == resultado)
    {
        cout << texto << " é um palindromo! " << endl;
    }
    else
    {
        cout << texto << " nao é um palindromo!" << endl;
    }
    
    

    return 0;
}
