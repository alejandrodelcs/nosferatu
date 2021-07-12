#include "ser.h"

Ser::Ser(int fila, int columna, std::string id, int vida, int ataque, int armadura, int energia) : Objeto(fila, columna, id){
	this->vida = vida;
	this->ataque = ataque;
    this->armadura = armadura;
    this->energia = energia;
};

void Ser::mostrar(){
    Objeto::mostrar();
}

void Ser::atacar(){
	std::cout << "ataco" << std::endl;
}

void Ser::defender(){
	std::cout << "defiendo" << std::endl;
}
