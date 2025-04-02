/*Crie um programa que tenha uma função para calcular a idade de uma pessoa em dias.
O usuário deve informar a idade em anos, meses e dias, e a função deve retornar o total correspondente em dias.*/

#include <iostream>

using namespace std;

bool SeAnoBisex(int anos, int &div, int &diasBisex, int &diasNormais, int &anosBisex, int &anosNormais, int &quantidadeTotal)
{

    div = anos / 4;
    anosBisex = div;
    diasBisex = anosBisex * 366;

    anosNormais = anos - anosBisex;
    diasNormais = anosNormais * 365;

    quantidadeTotal = diasBisex + diasNormais;

    return true;
}

int main()
{
    int meses, anos, dias, div;
    int anosNormais, diasNormais, anosBisex, diasBisex, quantidadeTotal = 0;

    cout << "Me informe sua idade em anos, meses e dias: ";
    cin >> anos >> meses >> dias;

    if (SeAnoBisex(anos, div, diasBisex, diasNormais, anosBisex, anosNormais, quantidadeTotal))
    {
        quantidadeTotal += (meses * 30) + dias;
        cout << "Voce tem " << quantidadeTotal << " dias de vida." << endl;
    }
    else
    {
        cout << "Erro!" << endl;
    }

    return 0;
}