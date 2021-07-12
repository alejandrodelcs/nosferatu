#include "vanesa.h"

Vanesa::Vanesa(int fila, int columna, std::string id, int vida, int ataque) : Cazavampiro(fila, columna, id, vida, ataque){
    this->fila = fila;
    this->columna = columna;
    this->simbolo = "W";
    this->id = id;
    this->vida = vida;
    this->ataque = ataque;
}

std::string Vanesa::obtenerSimbolo() {
    return simbolo;
}


void Vanesa::mostrar() {
    std::cout << "Vanesa Helsing" << std::endl;
}
