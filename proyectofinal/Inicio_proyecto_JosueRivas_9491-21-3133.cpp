#include <iostream>
#include <string>

using namespace std;

class persona
{
public:
    string nombre, iD, direccion, email, telefono;
    int edad;
    persona(string inombre, string iiD, string idireccion, string iemail, string itelefono, int iedad)
    {
        nombre=inombre;
        iD=iiD;
        direccion=idireccion;
        email=iemail;
        telefono=itelefono;
        edad=iedad;
    }
private:

};

class empleado : public persona
{
public:
    empleado(string inombre, string iiD, string idireccion, string iemail, string itelefono, int iedad):persona(inombre, iiD, idireccion, iemail, itelefono, iedad)
    {
        nombre=inombre;
        iD=iiD;
        direccion=idireccion;
        email=iemail;
        telefono=itelefono;
        edad=iedad;
    }
    void mensajeEmpleado()
    {
        cout << "Usted está en la clase empleado" << endl;
    }
private:

};

int main()
{
    empleado Josue("Josue", "sf456f", "12safa", "josuerivdl@gmail.com", "3107-5115", 18);
    Josue.mensajeEmpleado();
    return 0;
}
