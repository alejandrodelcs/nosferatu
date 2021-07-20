#include "ser.h"

int Ser::asignarVida() {
    return rand()%11+10;
}

int Ser::asignarAtaque() {
    return rand()%31+10;
}

int Ser::obtenerVida() {
    return this->vida;
}

int Ser::obtenerAtaque() {
    return this->ataque;
}
