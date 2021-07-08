#ifndef TP2_ZOMBIE_H
#define TP2_ZOMBIE_H

#include "monstruo.h"

class zombi : public Monstruo {
public:
    zombi(int fila, int columna);

    std::string devolverSimbolo() override;

    int devolverCantidad() override;

    int devolverFila() override;

    int devolverColumna() override;

    void mostrar() override;
};

#endif //TP2_ZOMBIE_H