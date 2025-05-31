/*
Utilizando um ponteiro para acessar os campos do registro.
a) Defina um registro Aluno com os campos nome e idade.
b) Defina uma variável do tipo registro.
c) Defina um ponteiro para este tipo de registro.
d) Por meio do ponteiro atribua valores a cada campo deste registro
*/

#include <iostream>

using namespace std;

struct Aluno
{
    string nome;
    int idade;
};

int main(){
    Aluno a1;
    Aluno* p;

    p = &a1;


    p->idade = 12;
    p->nome = "Magnum";


    cout << "A idade do aluno " << p->nome << " e " << p->idade << endl;

    return 0;
}