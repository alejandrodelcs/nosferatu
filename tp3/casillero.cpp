#include "casillero.h"

Casillero::Casillero(int fila,int col){
	this->terreno = "";
	this->hayPersonajeEnCasillero = false;
	this->hayElementoEnCasillero = false;
	this->personaje = nullptr;
	this->elemento = nullptr;
	this->fila=fila;
	this->col=col;
}


void Casillero::asignarTerreno(std::string terreno){
	this->terreno = terreno;
}


std::string Casillero::obtenerTerreno(){
	return terreno;
}


bool Casillero::hayPersonaje(){
	return hayPersonajeEnCasillero;
}


bool Casillero::hayElemento(){
	return hayElementoEnCasillero;
}


void Casillero::asignarPersonaje(Ser* nuevoPersonaje){
	personaje = nuevoPersonaje;
	hayPersonajeEnCasillero = true;
}


Ser* Casillero::obtenerPersonaje(){
	return personaje;
}


void Casillero::quitarPersonaje(){
	personaje = nullptr;
	hayPersonajeEnCasillero = false;
}


void Casillero::asignarElemento(Elemento* elementoNuevo){
	elemento = elementoNuevo;
	hayElementoEnCasillero = true;
}


Elemento* Casillero::obtenerElemento(){
	return elemento;
}


void Casillero::quitarElemento(){
	elemento = nullptr;
	hayElementoEnCasillero = false;
}
int Casillero::dar_fila() {
    return fila;
}
int Casillero::dar_col() {
    return  col;
}
