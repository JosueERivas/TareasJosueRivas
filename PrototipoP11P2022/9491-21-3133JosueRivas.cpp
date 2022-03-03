//librerias
#include <iostream>
using namespace std;

int main()
{
    //declarando Matrices
    int m1[3][3] = {{1, 1, 1}, {2, 2, 2}, {3, 3, 3}};
    int m2[3][3];
    //declarando Variables
    int x=0;
    int y=0;
    //declarando Limite Del Ciclo
    int i=3;
    //mensaje
    cout << "Los valores que se ingresan en la matriz son los siguentes: " << endl;
    //contador En "x"
    for(x=0; x < i; x++)
    {
        //contador En "y"
        for(y=0; y < i; y++)
        {
            //llenado De Matriz "m2"
            if (m1[x][y]%2 == 0)
            {
                m2[x][y] = 0;
                cout << m2[x][y];
            }
            else
            {
                m2[x][y] = 1;
                cout << m2[x][y];
            }
        }
        cout << endl;
    }
    return 0;
}
