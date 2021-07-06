#include "ItemVanesa.h"
#include <iostream>

ItemVanesa::ItemVanesa(int posX, int posY) : Items (posX, posY){
	// TODO Auto-generated constructor stub
	this->nombre = VANESA_STR;
	this->cantidad = 1;
}

void ItemVanesa::mostrar_contenido(){
	std::cout << "Nombre: " << this->nombre << std::endl;
	std::cout << "X: " << this->posX << std::endl;
	std::cout << "Y: " << this->posY << std::endl;
	std::cout << "cantidad: " << this->cantidad << std::endl;
	informar_cuadrantes();
	std::cout << std::endl;
}

ItemVanesa::~ItemVanesa() {
	// TODO Auto-generated destructor stub
}

