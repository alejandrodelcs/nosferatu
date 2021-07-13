#include "cazavampiro.h"

Cazavampiro::Cazavampiro(int fila, int columna, std::string id, int vida, int ataque, int armadura, int energia) : Humano(fila, columna, id, vida, ataque,armadura,energia) {
    this->simbolo = "H";
};

void Cazavampiro::mostrar() {
    std::cout << "Cazavampiro" << std::endl;
}

int Cazavampiro::obtenerColumna(){
	Humano::obtenerColumna();
}

int Cazavampiro::obtenerFila(){
	Humano::obtenerFila();
}

std::string Cazavampiro::obtenerId(){
	Humano::obtenerId();
}

std::string Cazavampiro::obtenerSimbolo(){
	Humano::obtenerSimbolo();
}

void Cazavampiro::atacar(){
	Humano::atacar();
}

void Cazavampiro::defender(){
	Humano::atacar();
}

