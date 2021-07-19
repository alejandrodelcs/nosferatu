#include "zombi.h"

Zombi::Zombi(int fila, int columna, std::string id) {
    this->fila = fila;
    this->columna = columna;
    this->simbolo = "z";
    this->id = id;
    this->vida = asignarVida();
    this->ataque = asignarAtaque();
}

std::string Zombi::obtenerSimbolo() {
    return simbolo;
}


void Zombi::mostrar() {
    std::cout << "el zombi" << std::endl;
}
