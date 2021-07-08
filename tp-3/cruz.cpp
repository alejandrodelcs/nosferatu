#include "cruz.h"

Cruz::Cruz(int fila, int columna) {
    this->fila = fila;
    this->columna = columna;
    this->simbolo = "c";
    this->cantidad = 1;
}

std::string Cruz::devolverSimbolo() {
    return simbolo;
}

int Cruz::devolverCantidad() {
    return cantidad;
}

int Cruz::devolverFila() {
    return fila;
}

int Cruz::devolverColumna() {
    return columna;
}

void Cruz::mostrar() {
    std::cout << "cruz" << std::endl;
}