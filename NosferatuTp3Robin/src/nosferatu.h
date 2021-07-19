#ifndef TP2_NOSFERATU_H
#define TP2_NOSFERATU_H

#include "vampiro.h"

class Nosferatu : public Vampiro {
public:
    Nosferatu(int fila, int columna, const std::string& id);

    std::string obtenerSimbolo();

    void mostrar();

    void atacar(){};
    void defender(){};

};

#endif //TP2_NOSFERATU_H
