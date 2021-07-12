#include "agua.h"

Agua::Agua(int fila, int columna, std::string id, int cantidad):Elemento(fila,columna,id,cantidad){
    this->simbolo = "a";
}

void Agua::mostrar() {
    Elemento::mostrar();
    std::cout << "agua" << std::endl;
}

