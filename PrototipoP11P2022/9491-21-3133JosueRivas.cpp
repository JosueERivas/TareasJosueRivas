#include <iostream>
using namespace std;

int main()
{
    int m1[3][3] = {{1, 1, 1}, {2, 2, 2}, {3, 3, 3}};
    int m2[3][3];
    int x=0;
    int y=0;
    int i=3;
    for(x=0; x < i; x++)
    {
        for(y=0; y < i; y++)
        {
            if (m1[x][y]%2 == 0)
            {
                m2[x][y] = 0;
            }
            else
            {
                m2[x][y] = 1;
            }
        }
    }
    cout << "%d , %d , %d" << m2[0][0] << m2[1][1] << m2[2][2];
    return 0;
}
