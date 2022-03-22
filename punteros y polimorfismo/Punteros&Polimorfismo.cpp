#include <iostream>

using namespace std;

int main() {
//Se definen las variables
  int* pi;//Variable en la que esta almacenada la direccion de memoria de pi
  int a = 5;//Definimos a=5
  int b = 1;//Definimos b=1
  pi = &a;//Direccion en memoria de a
  cout << "Valor actual variable (a): " << a << " " << &a << " Valor actual variable (b): " << b << " " << &b << " puntero: " << pi << endl;//Mostramos el valor actual de la varible a y b y sus direcciones de memoria, además de nuestro puntero pi
  pi = &b;//Direccion en memoria de b
  *pi = 10;//Definimos nuestro puntero = 10
  cout << "Valor posterior variable (a): " << a << " " << &a << " Valor posterior variable (b): " << b << " " << &b << " puntero: " << pi << endl;//Mostramos el valor posterior de la varible a y b y sus direcciones de memoria, además de nuestro puntero pi
  return 0;
}
