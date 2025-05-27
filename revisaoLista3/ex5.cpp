/*Inverter uma string: Escreva uma função recursiva para 
inverter uma string (ex: "abc" -> 
"cba").*/

#include <iostream>
#include <string.h>

using namespace std;

string inverter(string texto, int i){
    if (i < 0)
    {
        return ""; // Corrigido: return de string, não 0
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

    cout << "String invertida: " << inverter(texto, texto.length() - 1) << endl;

    return 0;
}
