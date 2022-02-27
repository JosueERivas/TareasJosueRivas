#include <iostream>

using namespace std;

int main()
{
    //inicializando variables
    int day = 03;
    int month = 11;
    int year = 1989;
    //ingresando dia y mes de nacimiento
    cout << "Naci el: ";
    cout << day << endl;
    cout << "," << endl;
    cout << month << endl;
    cout << "," << endl;
    //cout << year << endl;
    //mostrando año de nacimiento
    year = -1990;
    cout << year << endl;
    //inicializando variables
    bool isSleepy = true;
    bool isHungry = false;
    //mostrando
    cout << "is Hungry? ";
    cout << isHungry << endl;
    //asignando nuevo valor
    isHungry = isSleepy;
    cout << isHungry << endl;

    //inicializando variable
    float pi = 3.1416f;
    //mostrando variable
    cout << "El area del circulo es: ";
    cout << pi << endl;
    //inicializando variable
    char firstChar = 'h';
    char secondChar = 'o';
    char thirdChar = 'l';
    char fourthChar = 'a';
    //mostrando variable
    cout << firstChar << secondChar << thirdChar << fourthChar << endl;

    return 0;
}
