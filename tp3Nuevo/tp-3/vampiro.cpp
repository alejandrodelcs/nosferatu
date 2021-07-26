#include "vampiro.h"

Vampiro::Vampiro(int fila, int columna, std::string id) {
    this->fila = fila;
    this->columna = columna;
    this->simbolo = "v";
    this->id = id;
    this->vida = asignarVida();
    this->ataque = asignarAtaque();
}

std::string Vampiro::obtenerSimbolo() {
    return simbolo;
}


void Vampiro::mostrar() {
    std::cout << "Vampiro" << std::endl;
}

bool Vampiro::tomar_objeto(std::string objeto, int cant) {
    bool tomo_objeto=false;
    if(objeto=="e"){
        tomo_objeto=true;
    }
    return tomo_objeto;
}
bool Vampiro::esta_en_rango(int fila, int col) {
    return((fila == this->fila-1 && col == this->columna) ||
           (fila == this->fila && col == this->columna-1) ||
           (fila == this->fila+1 && col == this->columna) ||
           (fila == this->fila && col == this->columna+1));
}
