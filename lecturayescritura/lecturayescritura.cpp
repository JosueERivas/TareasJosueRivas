#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    //Creación de Archivo
    ofstream myfile ("GameData.txt");
    string NewName;
    //guarda el nombre en el archivo
    cout << "Ingrese su nombre: " << endl;
    cin >> NewName;
    if (myfile.is_open())
    {
        myfile << "Nombre:" << endl;
        myfile << NewName << endl;
        myfile << "Alumno de Programación III" << endl;
        myfile.close();
    }
    else
        cout << "Unable to open file";
    //Lectura de archivo
    string line;
    string PlayerName;
    int lineCount = 1;
    ifstream myfileRead ("GameData.txt");
    //lee el nombre almacenado en el archivo
      if (myfileRead.is_open())
      {
        while ( getline (myfileRead,line) )
        {
            //cout << line << endl;
          //  cout << line<< endl;
          if(lineCount == 2)
            {
                PlayerName = line;
            }

            lineCount++;
        }
        myfileRead.close();
      }else
      {
          cout << "Unable to open file";
      }
      //imprime el nombre almacenado en el archivo
      cout << "lectura el archivo " << endl;
      cout << PlayerName;
     return 0;
}
