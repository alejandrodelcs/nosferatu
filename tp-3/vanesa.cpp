#include "vanesa.h"

Vanesa::Vanesa(int fila, int columna) {
    this->fila = fila;
    this->columna = columna;
    this->simbolo = "W";
    this->cantidad = 1;
}

std::string Vanesa::devolverSimbolo() {
    return simbolo;
}

int Vanesa::devolverCantidad() {
    return cantidad;
}

int Vanesa::devolverFila() {
    return fila;
}

int Vanesa::devolverColumna() {
    return columna;
}

void Vanesa::mostrar() {
    std::cout << "Vanesa Helsin" << std::endl;
}