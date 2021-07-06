#include "ItemHumanoCV.h"
#include <iostream>

ItemHumanoCV::ItemHumanoCV (int posX, int posY) : Items(posX, posY){
	// TODO Auto-generated constructor stub
	this->nombre = HUMANO_CV_STR;
	this->cantidad = UNO;
}

void ItemHumanoCV::mostrar_contenido(){
	std::cout << "Nombre: " << this->nombre << std::endl;
	std::cout << "X: " << this->posX << std::endl;
	std::cout << "Y: " << this->posY << std::endl;
	std::cout << "cantidad: " << this->cantidad << std::endl;
	informar_cuadrantes();
	std::cout << std::endl;
}

ItemHumanoCV::~ItemHumanoCV() {
	// TODO Auto-generated destructor stub
}

