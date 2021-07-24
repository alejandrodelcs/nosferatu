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

bool Vampirella::tomar_objeto(std::string objeto, int cant) {
    bool tomo_objeto=false;
    if(objeto=="e"){
        tomo_objeto=true;
    }
    return tomo_objeto;
}
bool Vampirella::esta_en_rango(int fila, int col) {
    return((fila == this->fila-1 && col == this->columna) ||
           (fila == this->fila && col == this->columna-1) ||
           (fila == this->fila+1 && col == this->columna) ||
           (fila == this->fila && col == this->columna+1));
}