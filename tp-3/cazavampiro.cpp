#include "cazavampiro.h"

Cazavampiro::Cazavampiro(int fila, int columna, std::string id) : Humano(fila, columna, id) {
    this->fila = fila;
    this->columna = columna;
    this->simbolo = "H";
    this->id = id;
    this->vida = asignarVida();
    this->ataque = asignarAtaque();
}

std::string Cazavampiro::obtenerSimbolo() {
    return simbolo;
}

void Cazavampiro::mostrar() {
    std::cout << "Vanesa Helsing" << std::endl;
}


