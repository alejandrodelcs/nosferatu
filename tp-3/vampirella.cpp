#include "vampirella.h"

Vampirella::Vampirella(int fila, int columna) {
    this->fila = fila;
    this->columna = columna;
    this->simbolo = "V";
    this->cantidad = 1;
}

std::string Vampirella::devolverSimbolo() {
    return simbolo;
}

int Vampirella::devolverCantidad() {
    return cantidad;
}

int Vampirella::devolverFila() {
    return fila;
}

int Vampirella::devolverColumna() {
    return columna;
}

void Vampirella::mostrar() {
    std::cout << "Vampirella" << std::endl;
}