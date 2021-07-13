#include "estaca.h"

Estaca::Estaca(int fila, int columna, std::string id, int cantidad):Elemento(fila,columna,id,cantidad){
    this->simbolo = "e";
    this->cantidad = 1;
}

void Estaca::mostrar() {
    Elemento::mostrar();
    std::cout << "estaca" << std::endl;
}

void Estaca::mostrar(){
    Elemento::mostrar();
}

int Estaca::obtenerColumna(){
	Elemento::obtenerColumna();
}

int Estaca::obtenerFila(){
	Elemento::obtenerFila();
}

std::string Estaca::obtenerId(){
	Elemento::obtenerId();
}

std::string Estaca::obtenerSimbolo(){
	Elemento::obtenerSimbolo();
}

int Estaca::obtenerCantidad(){
    Elemento::obtenerCantidad();
}
