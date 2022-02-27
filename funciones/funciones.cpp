#include <iostream>

using namespace std;

//funciones:
//imprime un mensaje
void PrintCuteMessage()
{
    cout << "Eres increible!" << endl;
}
//imprime una cadena de caracteres
void Print(string message)
{
    cout << message << endl;
}
//evaula la condicion y develve un valor booleano
bool IsPlayerDead(int hp)
{
    if(hp <= 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
//imprime una respuesta segun el valor booleano
bool PrintBool(bool value)
{
    if(value == true)
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }
}
//devuelve la suma de dos valores ingresados
int GetAttackPower(int Damage, int Weapon)
{
    return Damage + Weapon;
}
//devuelcve la suma de dosvalores ingresados
int obtenerSuma(int Valor1, int Valor2)
{
    return Valor1 + Valor2;
}

int main()
{
    //imprime un mensaje
    PrintCuteMessage();
    PrintCuteMessage();
    //inicializando variables
    int hp = 20;
    int power = 5;
    int weapon  = 11;
    //imprime texto
    Print("Is Player dead????");
    // inicializando y asignando el valor booleanod y segun el resultado de la operacion
    bool isDead = IsPlayerDead( hp - GetAttackPower(power,weapon) );
    //imprime resultados
    PrintBool(isDead);
    Print("Este es el valor real de acuerdo a la compu");
    cout << isDead << endl;
    //realiza una suma
    Print("ejemplo de calculadora");
    int suma = obtenerSuma(power, weapon);
    Print("El resultado de la suma es:");
    cout << suma << endl;
    return 0;
}
