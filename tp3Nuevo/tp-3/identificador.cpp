#include "identificador.h"
Identificador::Identificador() {
    this->diccionarioPersonajes = nullptr;
}

void Identificador::inicializar(ABB<string, Objeto *> *diccionarioPersonajes){
	this->diccionarioPersonajes = diccionarioPersonajes;
}

string Identificador::dar_codigo(int opcion) {
    int min, max;
    string resultado;
    if (opcion == 1) min = 1, max = 49;
    else if (opcion == 2) min = 50, max = 99;
    else if (opcion == 3) min = 0, max = 1;
    else if (opcion == 4) min = 100, max = 199;
    else if (opcion == 5) min = 202, max = 299;
    else if (opcion == 6) min = 201, max = 202;
    else if (opcion == 7) min = 200, max = 201;
    else if (opcion == 8) min = 320, max = 339;
    else if (opcion == 9) min = 300, max = 319;
    else if (opcion == 10) min = 380, max = 999;
    else if (opcion == 11) min = 340, max = 359;
    else min = 360, max = 379;

    while (min < max) {
        if (min < 10) {
            resultado = "00" + to_string(min);
        } else if (min >= 10 && min < 100)
            resultado = "0" + to_string(min);

        if (!diccionarioPersonajes->esta(resultado)) {
            return resultado;
        }
        min++;
    }
    return nullptr;
    std::cout<<"puto";
}
