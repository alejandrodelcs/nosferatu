#include "cazavampiro.h"

Cazavampiro::Cazavampiro(int fila, int columna) {
    this->fila = fila;
    this->columna = columna;
    this->simbolo = "H";
    this->cantidad = 1;
}

std::string Cazavampiro::devolverSimbolo() {
    return simbolo;
}

void Cazavampiro::mostrar() {
    std::cout << "Vanesa Helsin" << std::endl;
}

int Cazavampiro::devolverCantidad() {
    return cantidad;
}

int Cazavampiro::devolverFila() {
    return fila;
}

int Cazavampiro::devolverColumna() {
    return columna;
}

