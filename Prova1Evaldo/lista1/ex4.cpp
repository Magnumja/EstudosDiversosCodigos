#include <iostream>
#include <cmath>

using namespace std;

void CalculoVolume(float raio, float &volume)
{
    volume = (4.0 / 3.0) * M_PI * pow(raio, 3);
}

int main()
{
    float raio, volume;

    cout << "Qual o valor do raio da esfera? ";
    cin >> raio;

    CalculoVolume(raio, volume);

    cout << "O valor do volume da esfera: " << volume << endl;

    return 0;
}
