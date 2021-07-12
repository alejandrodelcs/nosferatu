#include "vampiro.h"

Vampiro::Vampiro(int fila, int columna, std::string id, int vida, int ataque, int armadura, int energia):Monstruo(fila,columna,id,vida,ataque,armadura,energia) {
    this->simbolo = "v";
};


void Vampiro::mostrar() {
    std::cout << "Vampiro" << std::endl;
}

