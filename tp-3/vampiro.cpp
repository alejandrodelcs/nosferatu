#include "vampiro.h"

Vampiro::Vampiro(int fila, int columna, std::string id, int vida, int ataque) {
    this->fila = fila;
    this->columna = columna;
    this->simbolo = "v";
    this->id = id;
    this->vida = vida;
    this->ataque = ataque;
}

std::string Vampiro::obtenerSimbolo() {
    return simbolo;
}


void Vampiro::mostrar() {
    std::cout << "Vampiro" << std::endl;
}

