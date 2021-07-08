#include "humano.h"

Humano::Humano(int ancho, int alto) {
    this->fila = ancho;
    this->columna = alto;
    this->simbolo = "h";
    this->cantidad = 1;
}

std::string Humano::devolverSimbolo() {
    return simbolo;
}

int Humano::devolverCantidad() {
    return cantidad;
}

int Humano::devolverFila() {
    return fila;
}

int Humano::devolverColumna() {
    return columna;
}

void Humano::mostrar() {
    std::cout << "humano" << std::endl;
}


