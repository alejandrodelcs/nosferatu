#include "cruz.h"

Cruz::Cruz(int fila, int columna, std::string id, int cantidad){
    this->fila = fila;
    this->columna = columna;
    this->simbolo = "c";
    this->cantidad = 1;
    this->id = id;
}

std::string Cruz::obtenerSimbolo() {
    return simbolo;
}

//int Cruz::devolverCantidad() {
//    return cantidad;
//}


void Cruz::mostrar() {
    std::cout << "cruz" << std::endl;
}
