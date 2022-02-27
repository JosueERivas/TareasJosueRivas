#include <iostream>

using namespace std;

int main()
{
    //ingresando la edad
    int edad = 0;
    cout << "edad: ";
    cin >> edad;
    //es apto para votar
    if (edad < 18) {
        cout << "no puedes votar" << endl;
    } else if (edad > 40) {
        cout << "no puedes votar" << endl;
    } else {
        cout << "puedes votar" << endl;
    }
    return 0;
}
