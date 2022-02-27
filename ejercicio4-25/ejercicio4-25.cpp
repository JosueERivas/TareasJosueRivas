#include <iostream>

using namespace std;

int main()
{
    char cuadrado[19][19];

    int lado=0;
    char asterisco='*';
    char espacio=' ';
    int fila=0;
    int columna=0;
    int cabeza=0;
    int medio=0;
    int cola=0;

    cout << "Ingrese un valor entre 1 y 20: ";
    cin >> lado;
    if (lado>1 && lado<20)
    {
        cabeza=lado;
        --cabeza;
        while (columna<=cabeza)
        {
            cuadrado[fila][columna]=asterisco;
            cout << cuadrado[fila][columna];
            ++columna;
        }
        cout << endl;
        columna=0;
        ++fila;
        medio=lado;
        if(medio>2)
        {
            --medio;
            while (fila<medio)
            {
                cuadrado[fila][columna]=asterisco;
                cout << cuadrado[fila][columna];
                ++columna;
                while (columna<medio)
                {
                    cuadrado[fila][columna]=espacio;
                    cout << cuadrado[fila][columna];
                    ++columna;
                }
                cuadrado[fila][columna]=asterisco;
                cout << cuadrado[fila][columna];
                cout << endl;
                columna=0;
                ++fila;
            }
        }
        cola=lado;
        --cola;
        while (columna<=cola)
        {
            cuadrado[fila][columna]=asterisco;
            cout << cuadrado[fila][columna];
            ++columna;
        }
    }else
    {
        cout << "El numero ingresado no es valido.";
    }

    return 0;
}
