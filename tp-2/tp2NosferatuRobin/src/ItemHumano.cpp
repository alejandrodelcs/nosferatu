#include "ItemHumano.h"
#include <iostream>

ItemHumano::ItemHumano(int posX, int posY) : Items (posX, posY) {
	// TODO Auto-generated constructor stub
	this->nombre = HUMANO_STR;
	this->cantidad = UNO;
}

void ItemHumano::mostrar_contenido(){
	std::cout << "Nombre: " << this->nombre << std::endl;
	std::cout << "X: " << this->posX << std::endl;
	std::cout << "Y: " << this->posY << std::endl;
	std::cout << "cantidad: " << this->cantidad << std::endl;
	informar_cuadrantes();
	std::cout << std::endl;
}

ItemHumano::~ItemHumano() {
	// TODO Auto-generated destructor stub
}

