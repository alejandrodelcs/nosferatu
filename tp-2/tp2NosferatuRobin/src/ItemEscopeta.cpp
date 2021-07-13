#include "ItemEscopeta.h"
#include <iostream>

ItemEscopeta::ItemEscopeta(int posX, int posY) : Items (posX, posY) {
	// TODO Auto-generated constructor stub
	this->nombre = ESCOPETA_STR;
	this->cantidad = UNO;
}

void ItemEscopeta::mostrar_contenido(){
	std::cout << "Nombre: " << this->nombre << std::endl;
	std::cout << "X: " << this->posX << std::endl;
	std::cout << "Y: " << this->posY << std::endl;
	std::cout << "cantidad: " << this->cantidad << std::endl;
	informar_cuadrantes();
	std::cout << std::endl;
}

ItemEscopeta::~ItemEscopeta() {
	// TODO Auto-generated destructor stub
}

