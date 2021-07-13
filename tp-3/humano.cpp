#include "humano.h"

Humano::Humano(int fila, int columna, std::string id, int vida, int ataque){
    this->fila = fila;
    this->columna = columna;
    this->simbolo = "h";
    this->id = id;
    this->vida = vida;
    this->ataque = ataque;
}

std::string Humano::obtenerSimbolo() {
    return simbolo;
}

void Humano::mostrar() {
    std::cout << "humano" << std::endl;
}

void Humano::atacar(){
	std::cout << "ataco" << std::endl;
}

void Humano::defender(){
	std::cout << "defiendo" << std::endl;
}
