#include "ItemCruz.h"
#include <iostream>

ItemCruz::ItemCruz(int posX, int posY) : Items (posX, posY) {
	// TODO Auto-generated constructor stub
	this->nombre = CRUZ_STR;
	this->cantidad = UNO;
}

void ItemCruz::mostrar_contenido(){
	std::cout << "Nombre: " << this->nombre << std::endl;
	std::cout << "X: " << this->posX << std::endl;
	std::cout << "Y: " << this->posY << std::endl;
	std::cout << "cantidad: " << this->cantidad << std::endl;
	informar_cuadrantes();
	std::cout << std::endl;
}

ItemCruz::~ItemCruz() {
	// TODO Auto-generated destructor stub
}

