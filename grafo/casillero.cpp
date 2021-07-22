#include "casillero.h"

Casillero::Casillero(){
	this->terreno = "";
}


void Casillero::asignarTerreno(std::string terreno){
	this->terreno = terreno;
}


std::string Casillero::obtenerTerreno(){
	return terreno;
}



