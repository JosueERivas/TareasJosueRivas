#include<iostream>
#include<cstdlib>
#include<string>

using namespace std;

// Las funciones se declaran antes del main

// Void es si la funcion solo imprime datos
void imprimirCosas(){

    printf("Game over....");

}
//Clase padre
class Mage{
public:
    //Constructor
    Mage(int BasePower, int BaseHp, string name)
    {
        Power = BasePower;//Atributo
        hp = BaseHp;//Atributo
        Name = name;//Atributo
    }
    float Damage()//Metodo
    {
        return Power;
    }
    void GetDamage(int Value)//Metodo
    {
        hp= hp-Value;
    }
    int life()//Metodo
    {
        return hp;
    }
    string get_name()//Metodo
    {
        return Name;//Metodo
    }
protected:
    int Power, hp;//Atributos
    string Name;//Atributo
};

//Clase hija 1
class IceMage : public Mage //La clase mago de hielo hereda los metodos y atributos de la clase mago
{
    public:
    IceMage(int BasePower, int BaseHp, string name) : Mage(BasePower, BaseHp, name)
    {
        Power = BasePower + 1;//Aunmenta un punto de poder base que el poder base del mago
        hp = BaseHp +1;//Aunmenta un punto mas de vida que la vida base del mago
        Name = name;
    }
    int ice_attack(){

        return  (rand() % Power) + 1;//Implementa un ataque de hielo
    }
};

//Clase hija 2
class FireMage : public Mage //La clase mago de fuego hereda los metodos y atributos de la clase mago
{
    public:
    FireMage(int BasePower, int BaseHp, string name) : Mage(BasePower, BaseHp, name)
    {
        Power = BasePower;
        hp = BaseHp + 10;//Su diferencia con el mago normal es que aunmenta 10 puntos de salud
        Name = name;
    }
    int fire_attack(){
        return  (rand() % Power) + 1; //Implementa un ataque de fuego
    }
};
int main()
{
    Mage* Current_mage;
    Mage Harry(10, 100, "Harry");//Define la clase de mago, el valor del poder base, la vida base y el nombre del mago
    IceMage Dumbledore(11, 100, "Dumbledore");//Define la clase de mago, el valor del poder base, la vida base y el nombre del mago
    FireMage Gandalf(11,100, "Gandalf");//Define la clase de mago, el valor del poder base, la vida base y el nombre del mago
    //fuck_pointers();
    //imprimirCosas();
    bool chance = true;//Indica si hay oportunidad para el mago
    int attack_value;//Indica el valor del ataque
    for (int i=0;i<10;i++){
        if (chance){
            Current_mage = &Dumbledore;//Define la dirección de el mago
            attack_value = Dumbledore.ice_attack();//Genera un ataque de hielo
            cout<<" attack :"<<attack_value;//Muestra el valor del ataque del mago
            Current_mage->GetDamage(attack_value);//Muestra el daño causado a partir del daño del ataque
            cout<<Current_mage->get_name()<<"- current life :"<<Current_mage->life()<<endl;//Muestra la vida del mago
            chance = false;//No hay oportunidad para el mago
        }
        else {
            Current_mage = &Gandalf;//Muestra la dirección del mago
            attack_value = Gandalf.fire_attack();//Define el valor del ataque de fuego
            cout<<" attack :"<<attack_value;//Muestra el valor del ataque
            Current_mage->GetDamage(attack_value);//Define el daño recibido a partir del ataque recibido
            cout<<Current_mage->get_name()<<"- current life :"<<Current_mage->life()<<endl;//Muestra la vida de nuestro mago
            chance = true;//Si hay oportunidad para el mago
        };
    }
    return 0;
    //El polimorfismo puede notarse en el ataque ya que todos tienen un ataque, pero cada uno lo hace de distinta forma dependiendo su habilidad.
}
