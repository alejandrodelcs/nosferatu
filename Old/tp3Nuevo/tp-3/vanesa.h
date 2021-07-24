#ifndef TP2_VANESA_H
#define TP2_VANESA_H

#include "cazavampiro.h"

class Vanesa : public Cazavampiro {
public:
    Vanesa(int fila, int columna, std::string id);

    std::string obtenerSimbolo();

    void mostrar();

};

#endif //TP2_VANESA_H
