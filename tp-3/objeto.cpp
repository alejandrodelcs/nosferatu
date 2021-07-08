#include "objeto.h"

Objeto::Objeto() {
    this->fila = 0;
    this->columna = 0;
    this->cantidad = 0;
}

void Objeto::mostrar() {
    std::cout << this->fila << this->columna << std::endl;
}

