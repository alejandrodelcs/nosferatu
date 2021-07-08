#ifndef TP2_BALAS_H
#define TP2_BALAS_H

#include "elemento.h"

class Balas : public Elemento {
public:
    Balas(int fila, int columna, int cantidad);

    std::string devolverSimbolo() override;

    int devolverCantidad() override;

    int devolverFila() override;

    int devolverColumna() override;

    void mostrar() override;
};

#endif //TP2_BALAS_H
