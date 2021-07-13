#include "vanesa.h"

Vanesa::Vanesa(int fila, int columna, std::string id, int vida, int ataque, int armadura, int energia) : Cazavampiro(fila, columna, id, vida, ataque, armadura, energia){
    this->simbolo = "W";
}


void Vanesa::mostrar() {
    std::cout << "Vanesa Helsing" << std::endl;
}

int Vanesa::obtenerColumna(){
	Cazavampiro::obtenerColumna();
}

int Vanesa::obtenerFila(){
	Cazavampiro::obtenerFila();
}

std::string Vanesa::obtenerId(){
	Cazavampiro::obtenerId();
}

std::string Vanesa::obtenerSimbolo(){
	Cazavampiro::obtenerSimbolo();
}

void Vanesa::atacar(){
	Cazavampiro::atacar();
}

void Vanesa::defender(){
	Cazavampiro::atacar();
}