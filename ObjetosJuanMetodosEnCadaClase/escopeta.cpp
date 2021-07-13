#include "escopeta.h"

Escopeta::Escopeta(int fila, int columna, std::string id, int cantidad):Elemento(fila,columna,id,cantidad){
    this->simbolo = "E";
    this->cantidad = 1;
}

void Escopeta::mostrar() {
    Elemento::mostrar();
    std::cout << "escopeta" << std::endl;
}

void Escopeta::mostrar(){
    Elemento::mostrar();
}

int Escopeta::obtenerColumna(){
	Elemento::obtenerColumna();
}

int Escopeta::obtenerFila(){
	Elemento::obtenerFila();
}

std::string Escopeta::obtenerId(){
	Elemento::obtenerId();
}

std::string Escopeta::obtenerSimbolo(){
	Elemento::obtenerSimbolo();
}

int Escopeta::obtenerCantidad(){
    Elemento::obtenerCantidad();
}
