/*Inverter uma string: Escreva uma função 
recursiva para inverter uma string 
(ex: "abc" -> "cba").
*/

#include <iostream>
using namespace std;

string Inverter(string texto){
    if (texto.empty())
    {
        return "";
    }

    char primeiro = texto[0];

    string resto = texto.substr(1);

    return inverter(resto) + primeiro;
    

}

int main(){
    string texto;

    cout << "Digite o texto que deseja inverter: ";
    getline(cin, texto);

    string textoInvertido = Inverter(texto);

    cout << "Texto invertido: " << textoInvertido << endl;




}