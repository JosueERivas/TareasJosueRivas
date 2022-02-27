#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    double ventas=0;
    double salarioTotal=0;

    double salarioMensual=200.00;
    double porcentaje=0.09;

    while (ventas!=-1)
    {
        cout << "Introduzca las ventas en dolares (-1 para salir): $";
        cin >> ventas;
        if (ventas!=-1)
        {
            salarioTotal=ventas*porcentaje+salarioMensual;
            cout << "El salario es: $" << fixed << setprecision(2) << salarioTotal << endl;
        }
    }
    return 0;
}
