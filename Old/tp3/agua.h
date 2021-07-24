#ifndef TP2_AGUA_H
#define TP2_AGUA_H

#include "elemento.h"

class Agua : public Elemento {
public:
    Agua(int fila, int columna, std::string id, int cantidad);

    std::string obtenerSimbolo();

    //int devolverCantidad() override;

    void mostrar();
};

#endif //TP2_AGUA_H
