#include "balas.h"

Balas::Balas(int fila, int columna, std::string id, int cantidad){
    this->fila = fila;
    this->columna = columna;
    this->cantidad = cantidad;
    this->simbolo = "b";
    this->id = id;
}

std::string Balas::obtenerSimbolo() {
    return simbolo;
}

//int Balas::devolverCantidad() {
//    return cantidad;
//}


void Balas::mostrar() {
    std::cout << "balas" << std::endl;
}
