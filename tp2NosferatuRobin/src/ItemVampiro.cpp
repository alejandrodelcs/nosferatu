#include "ItemVampiro.h"
#include <iostream>

ItemVampiro::ItemVampiro(int posX, int posY) : Items(posX, posY) {
	// TODO Auto-generated constructor stub
	this->nombre = VAMPIRO_STR;
	this->cantidad = UNO;
}

void ItemVampiro::mostrar_contenido(){
	std::cout << "Nombre: " << this->nombre << std::endl;
	std::cout << "X: " << this->posX << std::endl;
	std::cout << "Y: " << this->posY << std::endl;
	std::cout << "cantidad: " << this->cantidad << std::endl;
	informar_cuadrantes();
	std::cout << std::endl;
}

ItemVampiro::~ItemVampiro() {
	// TODO Auto-generated destructor stub
}

