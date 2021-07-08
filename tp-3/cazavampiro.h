#ifndef TP2_CAZAVAMPIRO_H
#define TP2_CAZAVAMPIRO_H

#include "humano.h"

class Cazavampiro : public Humano {
public:
    Cazavampiro() = default;;

    Cazavampiro(int fila, int columna);

    std::string devolverSimbolo();

    int devolverCantidad();

    int devolverFila() override;

    int devolverColumna();

    void mostrar();
};

#endif //TP2_CAZAVAMPIRO_H
