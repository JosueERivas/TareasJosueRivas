#include <iostream>

using namespace std;

int main()
{
    //inicializando variables
    int a = 2;
    int b = 3;
    //inicializando arreglo
    int edades[] = { 24,20, 7 };
    cout << sizeof(edades) / sizeof(edades[0]);
    return 0;
}
