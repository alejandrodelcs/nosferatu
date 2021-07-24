#include "nosferatu.h"

Nosferatu::Nosferatu(int fila, int columna, const std::string& id) : Vampiro(fila, columna, id){
    this->fila = fila;
    this->columna = columna;
    this->simbolo = "N";
    this->id = id;
    this->vida = asignarVida();
    this->ataque = asignarAtaque();
}

std::string Nosferatu::obtenerSimbolo() {
    return simbolo;
}


void Nosferatu::mostrar() {
    std::cout << "Nosferatu" << std::endl;
}
