#include "nosferatu.h"

Nosferatu::Nosferatu(int fila, int columna, std::string id, int vida, int ataque, int armadura, int energia) : Vampiro(fila, columna, id, vida, ataque, armadura, energia){
    this->simbolo = "N";
};

void Nosferatu::mostrar() {
    std::cout << "Nosferatu" << std::endl;
}

int Nosferatu::obtenerColumna(){
	Vampiro::obtenerColumna();
}

int Nosferatu::obtenerFila(){
	Vampiro::obtenerFila();
}

std::string Nosferatu::obtenerId(){
	Vampiro::obtenerId();
}

std::string Nosferatu::obtenerSimbolo(){
	Vampiro::obtenerSimbolo();
}

void Nosferatu::atacar(){
	Vampiro::atacar();
}

void Nosferatu::defender(){
	Vampiro::atacar();
}