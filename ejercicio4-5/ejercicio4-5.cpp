#include <iostream>

using namespace std;

int main()
{
    unsigned int suma=0;
    unsigned int x=1;
    while (x<11)
    {
        suma+=x;
        x+=1;
    }
    cout << "La suma es: " << suma;
    return 0;
}
