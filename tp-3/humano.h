#ifndef TP2_HUMANO_H
#define TP2_HUMANO_H

#include "ser.h"

class Humano : public Ser {
public:
    Humano(int fila, int columna, std::string id);

    std::string obtenerSimbolo();

    void mostrar();

    void atacar();

    void defender();
};

#endif //TP2_HUMANO_H
