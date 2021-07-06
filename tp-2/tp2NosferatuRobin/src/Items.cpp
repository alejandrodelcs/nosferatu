#include "Items.h"
#include <iostream>

Items::Items(std::string nombre, int posicionX, int posicionY){
	this->nombre = nombre;
	this->posX = posicionX;
	this->posY = posicionY;
	//this->cantidad = 0; //lo inicializo acá nomás para que el IDE no me lo marque con un cartelito amarillo
}

Items::Items(int posX, int posY){
	this->posX = posX;
	this->posY = posY;
	//this->cantidad = 0;
}

void Items::asignar_nombre(std::string nombre){
	this->nombre = nombre;
}

void Items::asignar_coordX(int coordX){
	this->posX = coordX;
}

void Items::asignar_coordY(int coordY){
	this->posY = coordY;
}

int Items::obtener_cantidad_elemento(){
	return this->cantidad;
}

std::string Items::obtener_nombre(){
	return this->nombre;
}

int Items::obtener_coord_x(){
	return this->posX;
}

int Items::obtener_coord_y(){
	return this->posY;
}

bool Items::esta_en_NO(){
	return ((posX >= 1 && posX <= 3) && (posY >= 1 && posY <= 7));
}

bool Items::esta_en_NE(){
	return((posX >= 1 && posX <= 3) && (posY >= 8 && posY <= 14));
}

bool Items::esta_en_SO(){
	return((posX >= 4 && posX <= 6) && (posY >=1 && posY <= 7));
}

bool Items::esta_en_SE(){
	return((posX >= 4 && posX <= 6) && (posY >= 8 && posY <= 14));
}

void Items::informar_cuadrantes(){
	std::cout << "NO: " << esta_en_NO() << std::endl;
	std::cout << "NE: " << esta_en_NE() << std::endl;
	std::cout << "SO: " << esta_en_SO() << std::endl;
	std::cout << "SE: " << esta_en_SE() << std::endl;
}

Items::~Items() {
	// TODO Auto-generated destructor stub
}

