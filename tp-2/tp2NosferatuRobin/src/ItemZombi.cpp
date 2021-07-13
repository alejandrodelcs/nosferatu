#include "ItemZombi.h"
#include <iostream>

ItemZombi::ItemZombi(int posX, int posY) : Items(posX, posY){
	// TODO Auto-generated constructor stub
	this->nombre = ZOMBI_STR;
	this->cantidad = UNO;
}

void ItemZombi::mostrar_contenido(){
	std::cout << "Nombre: " << this->nombre << std::endl;
	std::cout << "X: " << this->posX << std::endl;
	std::cout << "Y: " << this->posY << std::endl;
	std::cout << "cantidad: " << this->cantidad << std::endl;
	informar_cuadrantes();
	std::cout << std::endl;
}

ItemZombi::~ItemZombi() {
	// TODO Auto-generated destructor stub
}

