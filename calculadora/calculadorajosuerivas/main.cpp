//librer�as
#include <iostream>
#include <wchar.h>
#include <locale.h>
#include <stdlib.h>


using namespace std;


//funciones
double operacionSuma (double valorA, double valorB)
{
    return valorA+valorB;
}

double operacionResta (double valorA, double valorB)
{
    return valorA-valorB;
}
double operacionMulti (double valorA, double valorB)
{
    return valorA*valorB;
}
double operaciondiv (double valorA, double valorB)
{
    return valorA/valorB;
}
void mostrarResultado()
{
    cout << "El resultado de la operaci�n es: ";
}


//main
int main()
{
    //caracteres Especiales
    setlocale(LC_ALL, "");


    //variables
    int menu=1;
    int a=0;
    double valorA=0;
    double valorB=0;
    double resultado=0;


    //menu
    while (menu!=0)
    {
        cout << "1. Suma" << endl << "2. Resta" << endl << "3. Multiplicaci�n" << endl << "4. Divisi�n" << endl << "0. Salir" << endl << "Ingrese el n�mero que corresponde a la operaci�n que desea realizar: ";
        cin >> menu;
        if (menu!=0){
            cout << "Ingrese el primer valor: ";
            cin >> valorA;
            cout << "Ingrese el segundo valor: ";
            cin >> valorB;
        }
        switch (menu)
        {
            case 1:
                mostrarResultado();
                cout << operacionSuma(valorA,valorB) << endl;
            break;
            case 2:
                mostrarResultado();
                cout << operacionResta(valorA,valorB)<< endl;
            break;
            case 3:
                mostrarResultado();
                cout << operacionMulti(valorA,valorB) << endl;
            break;
            case 4:
                mostrarResultado();
                cout << operaciondiv(valorA, valorB) << endl;
            break;
            case 0:
                cout << "Nos vemos.";
            break;
            default:
                cout << "El n�mero ingresado no es v�lido, intente de nuevo.";
            break;
        }
        if (menu!=0)
        {
            system("pause");
            system("cls");
        }
    }


    return 0;
}
