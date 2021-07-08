#include "vampiro.h"

Vampiro::Vampiro(int fila, int columna) {
    this->fila = fila;
    this->columna = columna;
    this->simbolo = "v";
    this->cantidad = 1;
}

std::string Vampiro::devolverSimbolo() {
    return simbolo;
}

int Vampiro::devolverCantidad() {
    return cantidad;
}

int Vampiro::devolverFila() {
    return fila;
}

int Vampiro::devolverColumna() {
    return columna;
}

void Vampiro::mostrar() {
    std::cout << "Vampiro" << std::endl;
}

