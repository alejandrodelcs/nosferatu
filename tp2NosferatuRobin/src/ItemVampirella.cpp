#include "ItemVampirella.h"
#include <iostream>

ItemVampirella::ItemVampirella(int posX, int posY) : Items(posX, posY){
	// TODO Auto-generated constructor stub
	this->nombre = VAMPIRELLA_STR;
	this->cantidad = UNO;
}

void ItemVampirella::mostrar_contenido(){
	std::cout << "Nombre: " << this->nombre << std::endl;
	std::cout << "X: " << this->posX << std::endl;
	std::cout << "Y: " << this->posY << std::endl;
	std::cout << "cantidad: " << this->cantidad << std::endl;
	informar_cuadrantes();
}

ItemVampirella::~ItemVampirella() {
	// TODO Auto-generated destructor stub
}

