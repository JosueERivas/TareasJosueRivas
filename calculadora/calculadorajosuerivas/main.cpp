#include <iostream>

using namespace std;

int main()
{
    double valora=0;
    double valorb=0;
    double valorsuma=0;
    double valorresta=0;
    double valormulti=0;
    double valordiv=0;
    cout << "Ingrese un primer valor: ";
    cin >> valora;
    cout << "Ingrese un segundo valor: ";
    cin >> valorb;
    valorsuma=valora+valorb;
    valorresta=valora-valorb;
    valormulti=valora*valorb;
    valordiv=valora/valorb;
    cout << "El resutado de la suma es: " << valorsuma << endl;
    cout << "El resutado de la resta es: " << valorresta << endl;
    cout << "El resutado de la multiplicación es: " << valormulti << endl;
    cout << "El resutado de la división es: " << valordiv << endl;
    return 0;
}
