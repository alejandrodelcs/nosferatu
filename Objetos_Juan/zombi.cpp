#include "zombi.h"

zombi::zombi(int fila, int columna, std::string id, int vida, int ataque,int armadura,int energia):Monstruo(fila,columna,id,vida,ataque,armadura, energia) {
    this->simbolo = "z";
}

void zombi::mostrar() {
    std::cout << "el zombi" << std::endl;
}
