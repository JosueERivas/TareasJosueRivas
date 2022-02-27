#include <iostream>

using namespace std;

int main()
{
    //inicializando variables
    int Math = 0;
    int Biology = 0;
    //ingresando valores
    cout << "Ingrese la nota de Matematicas" << endl;
    cin >> Math;
    cout << "Ingrese la nota de Biología" << endl;
    cin >> Biology;
    //realizando operaciones relacioonales
    cout << "Verificación operadores relacionales" << endl;
    cout << " Es mayor? " << (Math > Biology) << endl;
    cout << " Es menor? " << (Math < Biology) << endl;
    cout << " Es mayor o igual? " << (Math >= Biology) << endl;
    cout << " Es menor o igual? " << (Math <= Biology) << endl;
    cout << " Es igual? " << (Math == Biology) << endl;
    cout << " Es diferente? " << (Math != Biology) << endl;
    //se comenta la calificacion del alumno
    if(Math == 10)
    {
        cout << "el alumno es increible!" << endl;
    }
    else
    if(Math > 6)
    {
        cout << "el alumno esta aprobado" << endl;
    }
    else
        {
        cout << "el alumno esta reprobado" << endl;
    }
    //comentando la calificacion del alumno
    switch(Biology)
    {
    case 10:
        cout << "perfecto!!!" << endl;
        break;

    case 1:
        cout << "puntuacion baja" << endl;
        break;

    case 0:
        cout << "oh no! la calificacion minima!" << endl;
        break;

    default:
        cout << ":D" << endl;
        break;
    }
    return 0;
}
