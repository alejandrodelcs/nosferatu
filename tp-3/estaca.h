#ifndef TP2_ESTACA_H
#define TP2_ESTACA_H

#include "elemento.h"

class Estaca : public Elemento {
public:
    Estaca(int fila, int columna);

    std::string devolverSimbolo() override;

    int devolverCantidad() override;

    int devolverFila() override;

    int devolverColumna() override;

    void mostrar() override;
};

#endif //TP2_ESTACA_H
