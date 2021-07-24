#include "vanesa.h"

Vanesa::Vanesa(int fila, int columna, std::string id) : Cazavampiro(fila, columna, id){
    this->fila = fila;
    this->columna = columna;
    this->simbolo = "W";
    this->id = id;
    this->vida = asignarVida();
    this->ataque = asignarAtaque();
}

std::string Vanesa::obtenerSimbolo() {
    return simbolo;
}


void Vanesa::mostrar() {
    std::cout << "Vanesa Helsing" << std::endl;
}
