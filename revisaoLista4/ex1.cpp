#include <iostream>
#include <cstddef>
using namespace std;

/*Trocar valores de variáveis por meio de ponteiros.
a) Crie um programa que  declare duas variáveis inteiras e use um ponteiro para trocar seus valores.
b) Faça o mesmo para duas variáveis do tipo float e char*/

/*void trocarVariaveis(int *pont1,int *pont2){
    int aux = *pont1;
    *pont1 = *pont2;
    *pont2=aux;
}

int main(){
    int var1 = 5;
    int var2 = 25;

    cout << "Valor antes da troca de var1: " << var1 << " e o var2: " << var2 << "\n";

    trocarVariaveis(&var1, &var2);
    cout << "Valor depois da troca, var1: " << var1 << " e o de var2: " << var2 << endl;

    return 0;

}*/



//b)

void trocarFloat(float *pont1, float *pont2){
    float aux = *pont1;
    *pont1 = *pont2;
    *pont2 = aux;
}

void trocarChar(char *pont3, char *pont4){
    char aux2 = *pont3;
    *pont3 = *pont4;
    *pont4 = aux2;
}


int main(){
    float var1 = 5.4, var2 = 6.5;
    char var3 = 'a', var4 = 'b';

    cout << "Valor de var1 antes da troca: " << var1 << " e de var2: " << var2 << "\n";
    trocarFloat(&var1, &var2);
    cout << "Valor de var1 apos a troca: " << var1 << " e de var2: " << var2;


    cout << "\n" << "Valor antes de Var3 antes da troca: " << var3 << " e de var4: " << var4;
    trocarChar(&var3, &var4);
    cout << "\nValor apos a troca, de var3: " << var3 << " e de var4: " << var4 << endl;

    return 0;
}
