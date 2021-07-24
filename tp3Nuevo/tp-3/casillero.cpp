#include "casillero.h"

Casillero::Casillero(){
	this->terreno = "";
	this->hayPersonajeEnCasillero = false;
	this->hayElementoEnCasillero = false;
	this->personaje = nullptr;
	this->elemento = nullptr;
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


int Casillero::obtenerCostoTerreno(std::string clase){
	int peso;
	if (terreno == "M"){
		if (clase == "humano")
			peso = 2;
		else if (clase == "cazador")
			peso = 0;
		else
			peso = 1;
	}
	else if (terreno == "P"){
		if (clase == "humano" || clase == "cazador")
			peso = 2;
		else if (clase == "vampiro")
			peso = 0;
		else
			peso = 1;
	}
	else if (terreno == "L"){
		if (clase == "humano" || clase == "cazador")
			peso = 0;
		else if (clase == "vampiro")
			peso = 1;
		else
			peso = 2;
	}
	else if (terreno == "V"){
		if (clase == "humano" || clase == "cazador")
			peso = 1;
		else if (clase == "vampiro")
			peso = 2;
		else
			peso = 0;
	}
	else if (terreno == "C"){
		peso = 1;
	}
	else 				//Casillero con vacío (O)
		peso = 15;

	return peso;
}



