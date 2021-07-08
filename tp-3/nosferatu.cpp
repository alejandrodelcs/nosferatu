#include "nosferatu.h"

Nosferatu::Nosferatu(int fila, int columna) {
    this->fila = fila;
    this->columna = columna;
    this->simbolo = "N";
    this->cantidad = 1;
}

std::string Nosferatu::devolverSimbolo() {
    return simbolo;
}

int Nosferatu::devolverCantidad() {
    return cantidad;
}

int Nosferatu::devolverFila() {
    return fila;
}

int Nosferatu::devolverColumna() {
    return columna;
}

void Nosferatu::mostrar() {
    std::cout << "Nosferatu" << std::endl;
}