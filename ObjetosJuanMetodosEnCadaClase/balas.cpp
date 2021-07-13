#include "balas.h"

Balas::Balas(int fila, int columna, std::string id, int cantidad):Elemento(fila,columna,id,cantidad){
    this->simbolo = "b";
}

void Balas::mostrar() {
    Elemento::mostrar();
    std::cout << "balas" << std::endl;
}

void Balas::mostrar(){
    Elemento::mostrar();
}

int Balas::obtenerColumna(){
	Elemento::obtenerColumna();
}

int Balas::obtenerFila(){
	Elemento::obtenerFila();
}

std::string Balas::obtenerId(){
	Elemento::obtenerId();
}

std::string Balas::obtenerSimbolo(){
	Elemento::obtenerSimbolo();
}

int Balas::obtenerCantidad(){
    Elemento::obtenerCantidad();
}
