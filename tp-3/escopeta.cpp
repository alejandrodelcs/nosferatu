#include "escopeta.h"

Escopeta::Escopeta(int fila, int columna, std::string id, int cantidad){
    this->fila = fila;
    this->columna = columna;
    this->simbolo = "E";
    this->id = id;
    this->cantidad = 1;
}

std::string Escopeta::obtenerSimbolo() {
    return simbolo;
}

//int Escopeta::devolverCantidad() {
//    return cantidad;
//}


void Escopeta::mostrar() {
    std::cout << "escopeta" << std::endl;
}
