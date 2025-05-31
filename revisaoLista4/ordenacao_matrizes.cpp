#include<iostream>

#define FOR(i,n) for(int i = 0; i < n ; i++)
#define print cout <<
using namespace std;

int main(){
    int matriz[3][4] = {
        {1,2,3,5},
        {4,2,1,5},
        {5,3,1,6},
    };

    int linha, coluna;

    FOR(linha,3){
        FOR(coluna, 4){
            print "\t" << matriz[linha][coluna];
        }
        print endl;
    }


    return 0;
}