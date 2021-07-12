#include "balas.h"

Balas::Balas(int fila, int columna, std::string id, int cantidad):Elemento(fila,columna,id,cantidad){
    this->simbolo = "b";
}

void Balas::mostrar() {
    Elemento::mostrar();
    std::cout << "balas" << std::endl;
}
