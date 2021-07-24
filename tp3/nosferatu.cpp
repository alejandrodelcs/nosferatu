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

bool Nosferatu::tomar_objeto(std::string objeto, int cant) {
    bool tomo_objeto=false;
    if(objeto=="e"){
        tomo_objeto=true;
    }
    return tomo_objeto;
}
bool Nosferatu::esta_en_rango(int fila, int col) {
    return(fila<=this->fila+2 && col<=this->columna+2);
}
