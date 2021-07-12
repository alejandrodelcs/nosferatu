#include "escopeta.h"

Escopeta::Escopeta(int fila, int columna, std::string id, int cantidad):Elemento(fila,columna,id,cantidad){
    this->simbolo = "E";
    this->cantidad = 1;
}

void Escopeta::mostrar() {
    Elemento::mostrar();
    std::cout << "escopeta" << std::endl;
}
