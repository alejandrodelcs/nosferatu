#include "ser.h"

int Ser::asignarVida() {
    return rand()%11+10;
}

int Ser::asignarAtaque() {
    return rand()%31+10;
}
int Ser::asignarEnergia() {
    return rand()%20;
}
int Ser::asignarArmdura() {
    return rand()%2;
}

int Ser::obtenerVida() {
    return this->vida;
}

int Ser::obtenerAtaque() {
    return this->ataque;
}
int Ser::obtener_energia() {
    return energia;
}
void Ser::modificarEnergia(int gasto) {
    energia=gasto;
}
