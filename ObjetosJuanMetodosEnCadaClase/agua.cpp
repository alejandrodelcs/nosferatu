#include "agua.h"

Agua::Agua(int fila, int columna, std::string id, int cantidad):Elemento(fila,columna,id,cantidad){
    this->simbolo = "a";
}

void Agua::mostrar() {
    Elemento::mostrar();
    std::cout << "agua" << std::endl;
}

void Agua::mostrar(){
    Elemento::mostrar();
}

int Agua::obtenerColumna(){
	Elemento::obtenerColumna();
}

int Agua::obtenerFila(){
	Elemento::obtenerFila();
}

std::string Agua::obtenerId(){
	Elemento::obtenerId();
}

std::string Agua::obtenerSimbolo(){
	Elemento::obtenerSimbolo();
}

int Agua::obtenerCantidad(){
    Elemento::obtenerCantidad();
}
