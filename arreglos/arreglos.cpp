#include <iostream>

using namespace std;

//funciones
//muestra los valores de las celdas
void PrintCell(float Cells[], int index)
{
    cout << Cells[index] << endl;
}

//muestra una cadena de texto
void PrintMessage(string message)
{
    cout << message << endl;
}

int main()
{
    //arreglos
    float Grades[3];
    bool Enemies[2] = { false, true };
    string Names[5] = { "Roberto", "Lucia", "Alejandro", "Ana", "Luis"};
    //almacena nuevo valor para la posición
    Grades[2] = 3.1416f;
    //muestra los valores de cada posición
    PrintCell(Grades, 2);
    PrintCell(Grades, 1);
    PrintCell(Grades, 0);
    //almacena un nuevo valor para la posición
    cin >> Grades[0];
    //muestra el nuevo valor de la posicion
    PrintCell(Grades, 0);
    //muestra la cadena de texto
    PrintMessage(Names[1]);

    return 0;
}
