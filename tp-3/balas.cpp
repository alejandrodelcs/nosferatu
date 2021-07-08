#include "balas.h"

Balas::Balas(int fila, int columna, int cantidad) {
    this->fila = fila;
    this->columna = columna;
    this->cantidad = cantidad;
    this->simbolo = "b";
}

std::string Balas::devolverSimbolo() {
    return simbolo;
}

int Balas::devolverCantidad() {
    return cantidad;
}

int Balas::devolverFila() {
    return fila;
}

int Balas::devolverColumna() {
    return columna;
}

void Balas::mostrar() {
    std::cout << "balas" << std::endl;
}