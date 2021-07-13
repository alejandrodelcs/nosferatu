#include "nosferatu.h"

Nosferatu::Nosferatu(int fila, int columna, std::string id, int vida, int ataque) : Vampiro(fila, columna, id, vida, ataque){
    this->fila = fila;
    this->columna = columna;
    this->simbolo = "N";
    this->id = id;
    this->vida = vida;
    this->ataque = ataque;
}

std::string Nosferatu::obtenerSimbolo() {
    return simbolo;
}


void Nosferatu::mostrar() {
    std::cout << "Nosferatu" << std::endl;
}
