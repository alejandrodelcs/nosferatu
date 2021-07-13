#ifndef TP2_BALAS_H
#define TP2_BALAS_H

#include "elemento.h"

class Balas : public Elemento {
public:
    Balas(int fila, int columna, std::string id, int cantidad);

    std::string obtenerSimbolo();

    //int devolverCantidad();

    void mostrar() override;

};

#endif //TP2_BALAS_H
