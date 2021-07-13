#include "estaca.h"

Estaca::Estaca(int fila, int columna, std::string id, int cantidad){
    this->fila = fila;
    this->columna = columna;
    this->simbolo = "e";
    this->id = id;
    this->cantidad = 1;
}

std::string Estaca::obtenerSimbolo() {
    return simbolo;
}

//int Estaca::devolverCantidad() {
//    return cantidad;
//}

void Estaca::mostrar() {
    std::cout << "estaca" << std::endl;
}
