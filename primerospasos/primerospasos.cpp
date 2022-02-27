#include <iostream>

using namespace std;

int main()
{
    //inciializando variables
    int base=0;
    int altura= 0;
    int Edad = 0;
    char miLetraFavorita =' ';
    //ingresando edad
    cout << "Introduce tu edad: ";
    cin >> Edad;
    cout << endl << "Que joven, apenas tienes: " << Edad << endl;
    //calculando area
    cout << "Introduce la base de tu rectangulo: " << endl;
    cin >> base;
    cout << "Introduce la altura de tu rectangulo" << endl;
    cin >> altura;
    cout << "El area de tu rectangulo es: " << base * altura << endl;
    //letrafavorita
    cout << "Cual es tu letra favorita?" << endl;
    cin >> miLetraFavorita;
    cout << "Oh tambien la mia es: " << miLetraFavorita << endl;
}
