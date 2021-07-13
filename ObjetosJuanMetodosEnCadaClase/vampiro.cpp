#include "vampiro.h"

Vampiro::Vampiro(int fila, int columna, std::string id, int vida, int ataque, int armadura, int energia):Monstruo(fila,columna,id,vida,ataque,armadura,energia) {
    this->simbolo = "v";
};


void Vampiro::mostrar() {
    std::cout << "Vampiro" << std::endl;
}

int Vampiro::obtenerColumna(){
	Monstruo::obtenerColumna();
}

int Vampiro::obtenerFila(){
	Monstruo::obtenerFila();
}

std::string Vampiro::obtenerId(){
	Monstruo::obtenerId();
}

std::string Vampiro::obtenerSimbolo(){
	Monstruo::obtenerSimbolo();
}

void Vampiro::atacar(){
	Monstruo::atacar();
}

void Vampiro::defender(){
	Monstruo::atacar();
}