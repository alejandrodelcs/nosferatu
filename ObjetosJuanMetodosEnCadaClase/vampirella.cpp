#include "vampirella.h"

Vampirella::Vampirella(int fila, int columna, std::string id, int vida, int ataque, int armadura, int energia) : Vampiro(fila, columna, id, vida, ataque, armadura, energia){
    this->simbolo = "V";
};


void Vampirella::mostrar() {
    std::cout << "Vampirella" << std::endl;
}

int Vampirella::obtenerColumna(){
	Vampiro::obtenerColumna();
}

int Vampirella::obtenerFila(){
	Vampiro::obtenerFila();
}

std::string Vampirella::obtenerId(){
	Vampiro::obtenerId();
}

std::string Vampirella::obtenerSimbolo(){
	Vampiro::obtenerSimbolo();
}

void Vampirella::atacar(){
	Vampiro::atacar();
}

void Vampirella::defender(){
	Vampiro::atacar();
}