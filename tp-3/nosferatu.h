#ifndef TP2_NOSFERATU_H
#define TP2_NOSFERATU_H

#include "vampiro.h"

class Nosferatu : public Vampiro {
public:
    Nosferatu(int fila, int col);

    std::string devolverSimbolo() override;

    int devolverCantidad() override;

    int devolverFila() override;

    int devolverColumna() override;

    void mostrar() override;
};

#endif //TP2_NOSFERATU_H
