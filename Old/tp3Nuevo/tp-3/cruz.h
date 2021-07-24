#ifndef TP2_CRUZ_H
#define TP2_CRUZ_H

#include "elemento.h"

class Cruz : public Elemento {
public:
    Cruz(int fila, int columna, std::string id, int cantidad);

    std::string obtenerSimbolo();

    //int devolverCantidad();

    void mostrar();

};

#endif //TP2_CRUZ_H
