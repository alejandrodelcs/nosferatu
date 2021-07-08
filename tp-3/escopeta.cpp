#include "escopeta.h"

Escopeta::Escopeta(int fila, int columna) {
    this->fila = fila;
    this->columna = columna;
    this->simbolo = "E";
    this->cantidad = 1;
}

std::string Escopeta::devolverSimbolo() {
    return simbolo;
}

int Escopeta::devolverCantidad() {
    return cantidad;
}

int Escopeta::devolverFila() {
    return fila;
}

int Escopeta::devolverColumna() {
    return columna;
}

void Escopeta::mostrar() {
    std::cout << "escopeta" << std::endl;
}