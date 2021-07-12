#include "objeto.h"

Objeto::Objeto(int fila, int columna, std::string id) {
    this->fila = fila;
    this->columna = columna;
	this->id = id;
}

void Objeto::mostrar(){

}

int Objeto::obtenerFila(){
	return fila;
}

int Objeto::obtenerColumna(){
	return columna;
}


std::string Objeto::obtenerId(){
	return id;
}

std::string Objeto::obtenerSimbolo(){
	return simbolo;
}
