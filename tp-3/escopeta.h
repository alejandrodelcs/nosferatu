#ifndef TP2_ESCOPETA_H
#define TP2_ESCOPETA_H

#include "elemento.h"

class Escopeta : public Elemento {
public:
    Escopeta(int fila, int columna);

    std::string devolverSimbolo() override;

    int devolverCantidad() override;

    int devolverFila() override;

    int devolverColumna() override;

    void mostrar() override;
};

#endif //TP2_ESCOPETA_H
