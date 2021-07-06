#include "ItemBala.h"
#include <iostream>

ItemBala::ItemBala(int posX, int posY, int cantidad) : Items (posX, posY){
	// TODO Auto-generated constructor stub
	this->nombre = BALA_STR;
	this->cantidad = cantidad;
}

void ItemBala::mostrar_contenido(){
	std::cout << "Nombre: " << this->nombre << std::endl;
	std::cout << "X: " << this->posX << std::endl;
	std::cout << "Y: " << this->posY << std::endl;
	std::cout << "cantidad: " << this->cantidad << std::endl;
	informar_cuadrantes();
	std::cout << std::endl;
}

ItemBala::~ItemBala() {
	// TODO Auto-generated destructor stub
}

