#include "estaca.h"

Estaca::Estaca(int fila, int columna, std::string id, int cantidad):Elemento(fila,columna,id,cantidad){
    this->simbolo = "e";
    this->cantidad = 1;
}

void Estaca::mostrar() {
    Elemento::mostrar();
    std::cout << "estaca" << std::endl;
}
