#include <iostream>

using namespace std;

bool ValidarLetra(char caractere){
    return(caractere == 'A' || caractere == 'a' || caractere == 'P' || caractere == 'p');
}
int main(){
    char caractere;
    do
    {
        cout << "Me informe o caractere que deseja para validacao:";
        cout << "\n Obs: o caractere deve ser P,p,A,a!";
        cout << "\n digite: ";

        cin >> caractere;

        if (ValidarLetra(caractere))
        {
            cout << "Caractere aceito! Muito obrigado. " << endl;
        } else
        {
            cout << "Caractere Invalido! Tente novamente! \n";
        }
        
    } while (!ValidarLetra(caractere));
    
    return 0;
}