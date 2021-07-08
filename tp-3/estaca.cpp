#include "estaca.h"

Estaca::Estaca(int fila, int columna) {
    this->fila = fila;
    this->columna = columna;
    this->simbolo = "e";
    this->cantidad = 1;
}

std::string Estaca::devolverSimbolo() {
    return simbolo;
}

int Estaca::devolverCantidad() {
    return cantidad;
}

int Estaca::devolverFila() {
    return fila;
}

int Estaca::devolverColumna() {
    return columna;
}

void Estaca::mostrar() {
    std::cout << "estaca" << std::endl;
}