#ifndef TP2_CAZAVAMPIRO_H
#define TP2_CAZAVAMPIRO_H

#include "humano.h"

class Cazavampiro : public Humano {
public:
    Cazavampiro(int fila, int columna, std::string id);

    std::string obtenerSimbolo();

    void mostrar();
};

#endif //TP2_CAZAVAMPIRO_H
