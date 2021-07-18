#ifndef TP2_ESCOPETA_H
#define TP2_ESCOPETA_H

#include "elemento.h"

class Escopeta : public Elemento {
public:
    Escopeta(int fila, int columna, std::string id, int cantidad);

    std::string obtenerSimbolo();

    //int devolverCantidad();

    void mostrar();

};

#endif //TP2_ESCOPETA_H
