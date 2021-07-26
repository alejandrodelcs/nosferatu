#include "agua.h"

Agua::Agua(int fila, int columna, std::string id, int cantidad){
    this->fila = fila;
    this->columna = columna;
    this->cantidad = cantidad;
    this->id = id;
    this->simbolo = "a";
}

std::string Agua::obtenerSimbolo() {
    return simbolo;
}

void Agua::mostrar() {
    std::cout << "Agua" << std::endl;
    std::cout << "Cantidad: " << cantidad << std::endl;
}


//int Agua::devolverCantidad() {
//    return cantidad;
//}
