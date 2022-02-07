#include <iostream>

using namespace std;

int main()
{
    //Arreglos
    char nombreCurso[20][40];
    int notaCurso[20];


    //Variables
    int ingreso=0;
    int resultados=0;
    int cursos=0;
    char nombresCursos;


    //Ingreso cantidad de cursos
    cout << "Ingrese la cantidad de cursos a evaluar: ";
    cin >> cursos;


    //Ingreso de cursos y notas
    while (ingreso<cursos && cursos>0)
        {
        cout << "Ingrese el nombre del curso: ";
        cin >> nombreCurso[ingreso];
        cout << "Ingrese la nota obtenida: ";
        cin >> notaCurso[ingreso];
        ingreso=ingreso+1;
    }


    //cotinuar o salida en caso de ser 0 o menos
    if (cursos>0)
        {
        cout << "Sus resultados son:" << endl;


        //Mostrando Resultados
    }


    //Despedida
    cout << "Eso es todo.";
    return 0;
}
