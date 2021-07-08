#ifndef TP2_VANESA_H
#define TP2_VANESA_H

#include "cazavampiro.h"

class Vanesa : public Cazavampiro {
public:
    Vanesa(int fila, int columna);

    std::string devolverSimbolo() override;

    int devolverCantidad() override;

    int devolverFila() override;

    int devolverColumna() override;

    void mostrar() override;

};

#endif //TP2_VANESA_H
