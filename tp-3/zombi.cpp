#include "zombi.h"

zombi::zombi(int fila, int columna) {
    this->fila = fila;
    this->columna = columna;
    this->simbolo = "z";
    this->cantidad = 1;
}

std::string zombi::devolverSimbolo() {
    return simbolo;
}

int zombi::devolverCantidad() {
    return cantidad;
}

int zombi::devolverFila() {
    return fila;
}

int zombi::devolverColumna() {
    return columna;
}

void zombi::mostrar() {
    std::cout << "el zombi" << std::endl;
}