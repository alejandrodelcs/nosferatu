#include "vampirella.h"

Vampirella::Vampirella(int fila, int columna, std::string id, int vida, int ataque) : Vampiro(fila, columna, id, vida, ataque){
    this->fila = fila;
    this->columna = columna;
    this->simbolo = "V";
    this->id = id;
    this->vida = vida;
    this->ataque = ataque;
}

std::string Vampirella::obtenerSimbolo() {
    return simbolo;
}


void Vampirella::mostrar() {
    std::cout << "Vampirella" << std::endl;
}
