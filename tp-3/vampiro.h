#ifndef TP2_VAMPIRO_H
#define TP2_VAMPIRO_H

#include "monstruo.h"

class Vampiro : public Monstruo {
public:
    Vampiro(int fila, int columna, std::string id, int vida, int ataque);

    std::string obtenerSimbolo();

    void mostrar();

};

#endif //TP2_VAMPIRO_H
