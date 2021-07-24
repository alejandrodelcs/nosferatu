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
bool Zombi::tomar_objeto(std::string objeto, int cant) {
    bool tomo_objeto=false;
    if(objeto=="a"){
        tomo_objeto=true;
    }
    return tomo_objeto;
}
bool Zombi::esta_en_rango(int fila, int col) {
    return((fila == this->fila-1 && col == this->columna) ||
           (fila == this->fila && col == this->columna-1) ||
           (fila == this->fila+1 && col == this->columna) ||
           (fila == this->fila && col == this->columna+1));
}