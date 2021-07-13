#include "cruz.h"

Cruz::Cruz(int fila, int columna, std::string id, int cantidad):Elemento(fila,columna,id,cantidad){
    this->simbolo = "c";
    this->cantidad = 1;
}

void Cruz::mostrar() {
    Elemento::mostrar();
    std::cout << "cruz" << std::endl;
}

void Cruz::mostrar(){
    Elemento::mostrar();
}

int Cruz::obtenerColumna(){
	Elemento::obtenerColumna();
}

int Cruz::obtenerFila(){
	Elemento::obtenerFila();
}

std::string Cruz::obtenerId(){
	Elemento::obtenerId();
}

std::string Cruz::obtenerSimbolo(){
	Elemento::obtenerSimbolo();
}

int Cruz::obtenerCantidad(){
    Elemento::obtenerCantidad();
}
