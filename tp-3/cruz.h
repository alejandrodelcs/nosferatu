#ifndef TP2_CRUZ_H
#define TP2_CRUZ_H

#include "elemento.h"

class Cruz : public Elemento {
public:
    Cruz(int fila, int columna);

    std::string devolverSimbolo() override;

    int devolverCantidad() override;

    int devolverFila() override;

    int devolverColumna() override;

    void mostrar() override;
};

#endif //TP2_CRUZ_H
