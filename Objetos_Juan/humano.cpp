#include "humano.h"

Humano::Humano(int fila, int columna, std::string id, int vida, int ataque, int armadura, int energia):Ser(fila,columna,id,vida,ataque,armadura,energia){
    this->simbolo = "h";

};

void Humano::mostrar() {
    std::cout << "humano" << std::endl;
}
