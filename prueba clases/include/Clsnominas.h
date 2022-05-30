#ifndef CLSNOMINAS_H
#define CLSNOMINAS_H


class Clsnominas
{
    public:
        //Constructor de la clase nominas
        Clsnominas(int=0, string = "", int=0, string = "");

         //Menu de nominas
        mmenuNominas();

        //Crear registro en blanco
        mcrearNominas();

        //obtener valores de otras clases
        mobtenerValores( const Clsempleados &registro )

        //Metodos del CRUD de empleados
        int mobtenerIndicador( const char * const );

        void mnuevaNomina(fstream &archivoNomina);

        void mconsultarRegistroNomina(fstream &archivoNomina);

        void mostrarLineaNomina( const Clsnominas &registro );

        void mmodificarRegistroNomina( fstream &archivoNomina );

        void mmostrarLineaRegistroNomina( ostream &salida, const Clsempleados &registro );

        void mimprimirRegistroNomina(fstream &archivoEmpleado);

        void meliminarRegistroNomina(fstream &archivoNomina);

        void mbuscarNomina(fstream &archivoNomina);

        //Metodos atributo clase empelados
        void mestablecerIdNomina( int ) ;
        int mobtenerIdNomina() const;

        //Metodos atributo nombre del empleado
        void mestablecerNombreNomina( string );
        string mobtenerNombreNomina() const;

        //Metodos atributo clase empelados
        void mestablecerClaveEnomina( int ) ;
        int mobtenerClaveEnomina() const;

        //Metodos atributo nombre del empleado
        void mestablecerNombreENomina( string );
        string mobtenerNombreENomina() const;

        virtual ~Clsnominas();

    protected:

    private:
        int m_iclaveNominas;
        char m_snombreNomina;
        int m_iclaveEmpleadoNomina;
        char m_snombreEmpleadoNomina[10];
};

#endif // CLSNOMINAS_H
