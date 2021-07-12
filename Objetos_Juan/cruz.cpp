#include "cruz.h"

Cruz::Cruz(int fila, int columna, std::string id, int cantidad):Elemento(fila,columna,id,cantidad){
    this->simbolo = "c";
    this->cantidad = 1;
}

void Cruz::mostrar() {
    Elemento::mostrar();
    std::cout << "cruz" << std::endl;
}
