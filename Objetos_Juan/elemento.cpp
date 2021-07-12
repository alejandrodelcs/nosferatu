#include "elemento.h"


Elemento::Elemento(int fila, int columna, std::string id,int cantidad):Objeto(fila,columna,id){
	this->cantidad = cantidad;
};

int Elemento::obtenerCantidad(){
	return cantidad;
}

void Elemento::mostrar(){
    Objeto::mostrar();
}