/*Soma de uma lista: Crie uma
 função recursiva para somar todos os 
 elementos de uma lista de números.*/


 #include <iostream>

 using namespace std;

 int somarlista(int lista[], int tamanho){
    if (tamanho == 0)
    {
        return 0;
    }
    else{
        return lista[0] + somarlista(lista+1, tamanho-1);
    }
    
 }
 int main(){
    int tamanho;
    cout << "Digite o numero de elementos da lista: ";
    cin >> tamanho;

    int lista[tamanho];

    for (int i = 0; i < tamanho; i++)
    {
        cout << "Digite o elemento " << i+1 << ": ";
        cin >> lista[i];
    }
    
    int resultado = somarlista(lista, tamanho);


    cout << "A soma de todos os elementos da lista vale " << resultado << endl;

    return 0;
 }