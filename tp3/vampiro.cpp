#include "vampiro.h"

Vampiro::Vampiro(int fila, int columna, std::string id) {
    this->fila = fila;
    this->columna = columna;
    this->simbolo = "v";
    this->id = id;
    this->vida = asignarVida();
    this->ataque = asignarAtaque();
}

std::string Vampiro::obtenerSimbolo() {
    return simbolo;
}


void Vampiro::mostrar() {
    std::cout << "Vampiro" << std::endl;
}

