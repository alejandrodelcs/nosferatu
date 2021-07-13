#include "zombi.h"

zombi::zombi(int fila, int columna, std::string id, int vida, int ataque) {
    this->fila = fila;
    this->columna = columna;
    this->simbolo = "z";
    this->id = id;
    this->vida = vida;
    this->ataque = ataque;
}

std::string zombi::obtenerSimbolo() {
    return simbolo;
}


void zombi::mostrar() {
    std::cout << "el zombi" << std::endl;
}
