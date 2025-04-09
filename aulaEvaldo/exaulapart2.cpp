#include <iostream>
#include <fstream>
#include <string>
//procedimento referencia ponteiro
using namespace std;

void soma(int a, int b, int *r){
    *r = a+b;
}

int main(){
    int x,y,z;
    int *p;

    x =10;
    y = 20;
    z = 3;
    p = &z;

    cout << "Valor z: " << *p;

    soma (x,y,p); 

    cout << "\nSoma: " << *p;
    
    cout << "\n Z: " << z;
    return 0;




}
