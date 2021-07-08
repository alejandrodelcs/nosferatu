#include "agua.h"

Agua::Agua(int fila, int columna, int cantidad) {
    this->fila = fila;
    this->columna = columna;
    this->cantidad = cantidad;
    this->simbolo = "a";
}

std::string Agua::devolverSimbolo() {
    return simbolo;
}

void Agua::mostrar() {
    std::cout << "agua" << std::endl;
}

int Agua::devolverFila() {
    return fila;
}

int Agua::devolverColumna() {
    return columna;
}

int Agua::devolverCantidad() {
    return cantidad;
}