#include "Clsnominas.h"

//Librerias
#include<conio.h>
#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
#include<cstdlib>
#include<ctime>
#include<string.h>

Clsnominas::Clsnominas(int iclaveNomina, string snombreNomina, int iclaveEmpleado, string snombreEmpelado)
{
    //ctor
    mestablecerIdNomina(iclaveNomina);
    mestablecerNombreNomina(snombreNomina);
    mestablecerClave(iclaveEmpleado);
    mestablecerNombre(snombreEmpelado);
}

//Metodos del atributo clase nominas
int Clsnominas::mobtenerIdNomina() const
{
    return m_iclaveNominas;
}

void Clsnominas::mestablecerIdNomina (int ienteroClave)
{
    m_iclaveNominas = ienteroClave;
}

//Metodos atributo nombre de la nomina
string Clsnominas::mobtenerNombreNomina() const
{
    return m_snombreNomina;
}

void Clsnominas::mestablecerNombreNomina( string scadenaNombre )
{
   // copiar a lo m�s 20 caracteres de la cadena
   const char *svalorNombre = scadenaNombre.data();
   int ilongitud = strlen( svalorNombre );
   ilongitud = ( ilongitud < 10 ? ilongitud : 9 );
   strncpy( m_snombreNomina, svalorNombre, ilongitud );
   // anexar caracter nulo al final de la cadena
   m_snombreNomina[ ilongitud ] = '\0';
}

//Metodos del atributo clase empelados
int Clsnominas::mobtenerClaveEnomina() const
{
    return m_iclaveEmpleado;
}

void Clsnominas::mestablecerClaveEnomina (int ienteroClave)
{
    m_iclaveEmpleado = ienteroClave;
}

//Metodos atributo nombre del empleado
string Clsnominas::mobtenerNombreENomina() const
{
    return m_snombreEmpleado;
}

void Clsnominas::mestablecerNombreENomina( string scadenaNombre )
{
   // copiar a lo m�s 20 caracteres de la cadena
   const char *svalorNombre = scadenaNombre.data();
   int ilongitud = strlen( svalorNombre );
   ilongitud = ( ilongitud < 10 ? ilongitud : 9 );
   strncpy( m_snombreEmpleado, svalorNombre, ilongitud );
   // anexar caracter nulo al final de la cadena
   m_snombreEmpleado[ ilongitud ] = '\0';
}

//Metodos del CRUD de Nominas
Clsnominas::mcrearNominas()
{
    ofstream archivoNomina("registronominas.dat", ios::out | ios::binary);
    if(!archivoNomina)
    {
        cerr<<"No se habrio el archivo"<<endl;
        exit(1);
    }
    Clsnominas nominaEnBlanco;
    for(int i=0; i<100; i++)
    {
        archivoNomina.write(reinterpret_cast<const char * > (&nominaEnBlanco), sizeof(Clsnominas));
    }
}

int Clsnominas::mobtenerIndicador(const char * const iindicador)
{
    int m_iclaveNominas;
   // obtener el valor de la clave
   do
    {
      cout << iindicador << " (1 - 100): ";
      cin >> m_iclaveNominas;
    } while ( m_iclaveNominas < 1 || m_iclaveNominas > 100 );
   return m_iclaveNominas;
}

void Clsnominas::mtomarclave ( const Clsempleados &registro )
{
    char m_iclaveEmpleado[20] = registro.mobtenerClave();
    return m_iclaveEmpleado;
}

void Clsnominas::mtomarNombre ( const Clsempleados &registro )
{
    char m_snombreEmpleado[20] = registro.mobtenerNombre();
    return m_snombreEmpleado;
}

void Clsnominas::mnuevaNomina(fstream &archivoNomina)
{
   Clsnominas nomina;
   int m_iclaveNominas = mobtenerIndicador( "Escriba el numero de nomina" );
   // desplazar el apuntador de posici�n del archivo hasta el registro correcto en el archivo
   archivoNomina.seekg(
      ( m_iclaveNominas - 1 ) * sizeof( Clsnominas ) );
   // leer el registro del archivo
   archivoNomina.read( reinterpret_cast< char * >( &nomina ),
      sizeof( Clsnominas ) );
   // crear el registro, si �ste no existe ya
   if ( nomina.mobtenerClave() == 0 )
   {
        //Atributos a ingresar
        char m_snombreNomina[10];
        char m_iclaveEmpleado[10];
        char m_snombreEmpleado[10];
        //Solicitud al usuario de llenar los atributos
        cout << "Escriba el nombre de la nomina: " << endl;
        cin >> setw( 10 ) >> m_snombreNomina;
        //leer empleado
        Clsempleados empleado;
        int m_iclaveEmpleado = mobtenerIndicador("Ingrese la clave del empleado a agregar");
        archivoEmpleados.seekg(
        ( m_iclaveEmpleado - 1 ) * sizeof( Clsempleados ) );
        // leer el primer registro del archivo
        archivoEmpleados.read( reinterpret_cast< char * >( &empleado ),
        sizeof( Clsempleados ) );
        // actualizar el registro
        if ( empleado.mobtenerClave() != 0 )
        {
            m_iclaveEmpleado = mtomarNombre (archivoEmpleados);
            m_snombreEmpleado = mtomarclave (archivoEmpleados);
            cout << endl;
        }
        // mostrar error si la clave no contiene informacion
        else
        {
            cerr << "La la clave #" << m_iclaveEmpleado
            << " no tiene informacion." << endl;
        }
        // usar valores para llenar los valores de la clave
        nomina.mestablecerClave( m_inombreNomina );
        nomina.mestablecerNombre( m_iclaveEmpleado );
        nomina.mestablecerNombres(m_snombreEmpleado);
        // desplazar el apuntador de posici�n de archivo hasta el registro correcto en el archivo
        archivoNomina.seekp( ( m_iclaveNominas - 1 ) *
        sizeof( Clsnominas ) );
        // insertar el registro en el archivo
        archivoNomina.write(
         reinterpret_cast< const char * >( &nomina ),
         sizeof( Clsnominas ) );
        cout << "Empleado agregado con exito.";
   }
   // mostrar error si la clave ya esta ocupada
   else
   {
       cerr << "La clave #" << m_iclaveNominas << " ya contiene informacion." << endl;
       getch();
   }
}

void Clsnominas::mostrarLineaNomina( const Clsnominas &registro )
{
       cout << left << setw( 10 ) << registro.mobtenerIdNomina()
          << setw( 10 ) << registro.mobtenerNombreNomina().data()
          << setw( 10 ) << registro.mobtenerClaveEnomina().data()
          << setw( 10 ) << registro.mobtenerNombreENomina().data()
          << endl;
}

void Clsnominas::mconsultarRegistroNomina(fstream &archivoNomina)
{
    //Creando encabezado de la tabla
    cout << left << setw( 10 ) << "Clave Nomina"
    << setw( 10 ) << "Nombre nomina"
    << setw( 10 ) << "Clave empleado"
    << setw( 10 ) << "Nombre empleado"
    << endl;
    // colocar el apuntador de posici�n de archivo al principio del archivo de registros
    archivoNomina.seekg( 0 );
    // leer el primer registro del archivo de registros
    Clsnominas nomina;
    archivoNomina.read( reinterpret_cast< char * >( &nomina ),
    sizeof( Clsnominas ) );
    // copiar todos los registros del archivo de registros en el archivo de texto
    while ( !archivoNomina.eof() )
    {
        // escribir un registro individual en el archivo de texto
        if ( nomina.mobtenerClave() != 0 )
        mostrarLineaNomina(nomina);
        // leer siguiente registro del archivo de registros
        archivoNomina.read( reinterpret_cast< char * >( &nomina ),
        sizeof( Clsnominas ) );
    }
}
/*
void Clsempleados::mmostrarLineaRegistroEmpleados( ostream &salida, const Clsempleados &registro )
{
       salida << left << setw( 10 ) << registro.mobtenerClave()
          << setw( 10 ) << registro.mobtenerNombre().data()
          << setw( 20 ) << registro.mobtenerNombres().data()
          << setw( 10 ) << registro.mobtenerApellido().data()
          << setw( 20 ) << registro.mobtenerApellidos().data()
          << setw( 5 ) << registro.mobtenerEdad().data()
          << setw( 20 ) << registro.mobtenerDireccion().data()
          << setw( 10 ) << registro.mobtenerTelefono().data()
          << setw( 30 ) << registro.mobtenerCorreo().data()
          << setw( 10 ) << registro.mobtenerSexo().data()
          << setw( 15 ) << registro.mobtenerNacionalidad().data()
          << setw( 15 ) << registro.mobtenerNacimiento().data()
          << endl;
}

void Clsempleados::mmodificarRegistroEmpleados( fstream &archivoEmpleados )
{
    Clsempleados empleado;
    int m_iclaveEmpleado = mobtenerIndicador("Ingrese la clave del empleado");
    archivoEmpleados.seekg(
    ( m_iclaveEmpleado - 1 ) * sizeof( Clsempleados ) );
    // leer el primer registro del archivo
    archivoEmpleados.read( reinterpret_cast< char * >( &empleado ),
    sizeof( Clsempleados ) );
    // actualizar el registro
    if ( empleado.mobtenerClave() != 0 )
    {
        mmostrarLineaRegistroEmpleados( cout, empleado );
        cout << endl    ;
        //Atributos a ingresar
        char m_snombreEmpleado[10];
        char m_snombresEmpleado[20];
        char m_sapellidoEmpleado[10];
        char m_sapellidosEmpleado[20];
        char m_sedadEmpleado[5];
        char m_sdireccionEmpleado[20];
        char m_stelefonoEmpleado[10];
        char m_scorreoEmpleado[30];
        char m_ssexoEmpleado[10];
        char m_snacionalidadEmpleado[15];
        char m_snacimientoEmpleado[15];
        //Solicitud al usuario de llenar los atributos
        cout << "Escriba el primer nombre del empleado: " << endl;
        cin >> setw( 20 ) >> m_snombreEmpleado;
        cout << "Escriba segundo y/o tercer nombre del empleado: " << endl;
        cin >> setw( 20 ) >> m_snombresEmpleado;
        cout << "Escriba el primer apellido del empleado: " << endl;
        cin >> setw( 20 ) >> m_sapellidoEmpleado;
        cout << "Escriba segundo y/o tercer apellido del empleado: " << endl;
        cin >> setw( 20 ) >> m_sapellidosEmpleado;
        cout << "Escriba la edad del empleado: " << endl;
        cin >> setw( 5 ) >> m_sedadEmpleado;
        cout << "Escriba la direccion del empleado: " << endl;
        cin >> setw( 20 ) >> m_sdireccionEmpleado;
        cout << "Escriba el telefono del empleado: " << endl;
        cin >> setw( 20 ) >> m_stelefonoEmpleado;
        cout << "Escriba el correo del empleado: " << endl;
        cin >> setw( 20 ) >> m_scorreoEmpleado;
        cout << "Escriba el sexo del empleado: " << endl;
        cin >> setw( 10 ) >> m_ssexoEmpleado;
        cout << "Escriba la nacionalidad del empleado: " << endl;
        cin >> setw( 20 ) >> m_snacionalidadEmpleado;
        cout << "Escriba la fecha de nacimiento del empleado: " << endl;
        cin >> setw( 20 ) >> m_snacimientoEmpleado;
        // usar valores para llenar los valores de la clave
        empleado.mestablecerClave( m_iclaveEmpleado );
        empleado.mestablecerNombre( m_snombreEmpleado );
        empleado.mestablecerNombres(m_snombresEmpleado);
        empleado.mestablecerApellido(m_sapellidoEmpleado);
        empleado.mestablecerApellidos(m_sapellidosEmpleado);
        empleado.mestablecerEdad(m_sedadEmpleado);
        empleado.mestablecerDireccion(m_sdireccionEmpleado);
        empleado.mestablecerTelefono(m_stelefonoEmpleado);
        empleado.mestablecerCorreo(m_scorreoEmpleado);
        empleado.mestablecerSexo(m_ssexoEmpleado);
        empleado.mestablecerNacionalidad(m_snacionalidadEmpleado);
        empleado.mestablecerNacimiento(m_snacimientoEmpleado);
        mmostrarLineaRegistroEmpleados( cout, empleado );
        // desplazar el apuntador de posici�n de archivo hasta el registro correcto en el archivo
        archivoEmpleados.seekp(
        ( m_iclaveEmpleado - 1 ) * sizeof( Clsempleados ) );
        // escribir el registro actualizado sobre el registro anterior en el archivo
        archivoEmpleados.write(
        reinterpret_cast< const char * >( &empleado ),
        sizeof( Clsempleados ) );
        cout << "Empleado modificado con �xito.";
    }
    // mostrar error si la clave no contiene informacion
    else
    cerr << "La la clave #" << m_iclaveEmpleado
         << " no tiene informacion." << endl;
}

void Clsempleados::mimprimirRegistroEmpleados(fstream &archivoEmpleado)
{
    Clsempleados empleado;
    ofstream imprimir("registrodeempleados.txt", ios::out);
    // salir del programa si ofstream no puede crear el archivo
    if ( !imprimir )
    {
        cerr << "No se pudo crear el archivo." << endl;
        exit( 1 );

    }
    imprimir << left << setw( 10 ) << "Clave"
    << setw( 10 ) << "Nombre"
    << setw( 20 ) << "Nombres"
    << setw( 10 ) << "Apellido"
    << setw( 20 ) << "Apellidos"
    << setw( 5 ) << "Edad"
    << setw( 20 ) << "Direccion"
    << setw( 10 ) << "Telefono"
    << setw( 30 ) << "Correo"
    << setw( 10 ) << "Sexo"
    << setw( 15 ) << "Nacionalidad"
    << setw( 15 ) << "Fecha de nacimiento"
    << endl;
    // colocar el apuntador de posici�n de archivo al principio del archivo de registros
    archivoEmpleado.seekg( 0 );
    // leer el primer registro del archivo de registros
    archivoEmpleado.read( reinterpret_cast< char * >( &empleado ),
    sizeof( Clsempleados ) );
    // copiar todos los registros del archivo de registros en el archivo de texto
    while ( !archivoEmpleado.eof() )
    {
        // escribir un registro individual en el archivo de texto
        if ( empleado.mobtenerClave() != 0 )
        mmostrarLineaRegistroEmpleados( imprimir, empleado );
        // leer siguiente registro del archivo de registros
        archivoEmpleado.read( reinterpret_cast< char * >( &empleado ),
        sizeof( Clsempleados ) );
   }
   cout << "archivo creado con �xito con el nombre de: registrodeempleados.txt";
}

void Clsempleados::meliminarRegistroEmpleados(fstream &archivoEmpleados)
{
    int iindicador= mobtenerIndicador( "Escriba la clave a eliminar" );
    // desplazar el apuntador de posici�n de archivo hasta el registro correcto en el archivo
    archivoEmpleados.seekg(
    ( iindicador - 1 ) * sizeof( Clsempleados ) );
    // leer el registro del archivo
    Clsempleados empleado;
    archivoEmpleados.read( reinterpret_cast< char * >( &empleado ),
    sizeof( Clsempleados ) );
    // eliminar el registro, si es que existe en el archivo
    if ( empleado.mobtenerClave() != 0 )
    {
        Clsempleados empleadoEnBlanco;
        // desplazar el apuntador de posici�n de archivo hasta el registro correcto en el archivo
        archivoEmpleados.seekp( ( iindicador - 1 ) *
        sizeof( Clsempleados ) );
        // reemplazar el registro existente con un registro en blanco
        archivoEmpleados.write(
        reinterpret_cast< const char * >( &empleadoEnBlanco ),
        sizeof( Clsempleados ) );
        cout << "Empleado clave #" << iindicador << " eliminado correctamente.\n";
   }
   // mostrar error si el registro esta vacio
   else
   {
       cerr << "Empleado clave #" << iindicador << " esta vacia.\n";
   }
   getch();
}

void Clsempleados::mbuscarEmpleados(fstream &archivoEmpleados)
{
    int iindicador = mobtenerIndicador( "Escriba la clave que desea buscar" );
    // desplazar el apuntador de posici�n de archivo hasta el registro correcto en el archivo
    archivoEmpleados.seekg(
    ( iindicador - 1 ) * sizeof( Clsempleados ) );
    // leer el primer registro del archivo
    Clsempleados empleado;
    archivoEmpleados.read( reinterpret_cast< char * >( &empleado ),
    sizeof( Clsempleados ) );
    if ( empleado.mobtenerClave() != 0 )
    {
        mmostrarLineaRegistroEmpleados( cout, empleado );
    }
    // mostrar error si la clave esta vacia
    else
    {
        cerr << "La clave #" << iindicador
        << " no tiene informacion." << endl;
    }
    getch();
}
*/

Clsnominas::mmenuNominas()
{
    int iseleccionMenuNomina;
    do
    {
        system("cls");
        // abrir el archivo en modo de lectura y escritura
        fstream archivoNomina("registrosempleados.dat", ios::in | ios::out | ios::binary);
        // salir del programa si fstream no puede abrir el archivo
        if ( !archivoNomina )
            {
                cerr << "No se pudo abrir el archivo." << endl;
                mcrearNominas();
                cout <<  "Archivo creado satisfactoriamente, pruebe de nuevo";
                exit ( 1 );
            }
        cout<<"-------------------------------"<<endl;
        cout<<"|   SISTEMA GESTION Nomina  |"<<endl;
        cout<<"-------------------------------"<<endl;
        cout<<"1. Ingreso Empleados"<<endl;
        cout<<"2. Despliegue Empleados"<<endl;
        cout<<"3. Modifica Empleados"<<endl;
        cout<<"4. Imprimir Regisro de Empleados"<<endl;
        cout<<"5. Borra Empleados"<<endl;
        cout<<"6. Buscar Empleados"<<endl;
        cout<<"0. Volver al menu superior"<<endl;
        cout<<"-------------------------------"<<endl;
        cout<<"Opcion a escoger:[1/2/3/4/5/6/0]"<<endl;
        cout<<"------------------------------"<<endl;
        cout<<"Ingresa tu Opcion: ";
        cin>>iseleccionMenuNomina;
        switch(iseleccionMenuNomina)
        {
        case 1:
            {
                system("cls");
                mnuevaNomina(archivoNomina);
                getch();
            }
            break;
        case 2:
            {
                system("cls");
                mconsultarRegistroNomina(archivoNomina);
                cout << "Fin del archivo.";
                getch();
            }
            break;
        /*case 3:
            {
                system("cls");
                mmodificarRegistroEmpleados(archivoEmpleados);
                getch();
            }
            break;
        case 4:
            {
                system("cls");
                mimprimirRegistroEmpleados(archivoEmpleados);
                getch();
            }
            break;
        case 5:
            {
                system("cls");
                meliminarRegistroEmpleados(archivoEmpleados);
            }
            break;
        case 6:
            {
                system("cls");
                mbuscarEmpleados(archivoEmpleados);
            }
            break;*/
        case 0:
            break;
        default:
            cout<<"Opci�n invalida, intenta de nuevo";
            getch();
            break;
        }
    }while(iseleccionMenuNomina!=0);
}

Clsnominas::~Clsnominas()
{
    //dtor
}
