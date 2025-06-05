/*
Modifique o exercício anterior para receber os dados de 3 alunos (Vetor de registros) 
e fazer toda a manipulação dos registros por meio de um ponteiro.
a) Preencher todos os registros
b) Mostrar o conteúdo
*/

#include <iostream>
#include <cstdlib>

using namespace std;

struct Aluno{
    string nome;
    int idade;
};

int main(){
    
    Aluno* p;
    p = (Aluno*)malloc(3*sizeof(Aluno));

    

    for (int i = 0; i < 3; i++)
    {
        cout << "Digite o nome do " << (i+1) << " aluno: ";
        cin.ignore();
        getline(cin,p[i].nome);

        cout << "Digite a idade dele: ";
        cin >> p[i].idade;
    }

    system("cls");

    for (int i = 0; i < 3; i++)
    {
        cout << "O " << (i+1) << " Aluno de nome " << p[i].nome << " tem " << p[i].idade << " anos!"<< endl;
    }

    return 0;
    
    
}