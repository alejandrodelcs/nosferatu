#include "cazavampiro.h"

Cazavampiro::Cazavampiro(int fila, int columna, std::string id, int vida, int ataque, int armadura, int energia) : Humano(fila, columna, id, vida, ataque,armadura,energia) {
    this->simbolo = "H";
};

void Cazavampiro::mostrar() {
    std::cout << "Vanesa Helsing" << std::endl;
}


