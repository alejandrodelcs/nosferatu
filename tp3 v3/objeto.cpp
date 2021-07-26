#include "objeto.h"

int Objeto::obtenerFila(){
	return fila;
}

int Objeto::obtenerColumna(){
	return columna;
}


std::string Objeto::obtenerId(){
	return id;
}


void Objeto::asignarFila(int fila){
	this->fila = fila;
}

void Objeto::asignarColumna(int columna){
	this->columna = columna;
}
