#include "vampirella.h"

Vampirella::Vampirella(int fila, int columna, std::string id) : Vampiro(fila, columna, id){
    this->fila = fila;
    this->columna = columna;
    this->simbolo = "V";
    this->id = id;
    this->vida = asignarVida();
    this->ataque = asignarAtaque();
}

std::string Vampirella::obtenerSimbolo() {
    return simbolo;
}


void Vampirella::mostrar() {
    std::cout << "Vampirella" << std::endl;
}
