#include "cazavampiro.h"

Cazavampiro::Cazavampiro(int fila, int columna, std::string id, int vida, int ataque) : Humano(fila, columna, id, vida, ataque) {
    this->fila = fila;
    this->columna = columna;
    this->simbolo = "H";
    this->id = id;
    this->vida = vida;
    this->ataque = ataque;
}

std::string Cazavampiro::obtenerSimbolo() {
    return simbolo;
}

void Cazavampiro::mostrar() {
    std::cout << "Vanesa Helsing" << std::endl;
}


