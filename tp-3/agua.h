#ifndef TP2_AGUA_H
#define TP2_AGUA_H

#include "elemento.h"

class Agua : public Elemento {
public:
    Agua(int fila, int columna, int cantidad);

    std::string devolverSimbolo() override;

    int devolverCantidad() override;

    int devolverFila() override;

    int devolverColumna() override;

    void mostrar() override;
};

#endif //TP2_AGUA_H
