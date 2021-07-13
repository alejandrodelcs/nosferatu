#ifndef TP2_CRUZ_H
#define TP2_CRUZ_H

#include "elemento.h"

class Cruz : public Elemento {
public:
    Cruz(int fila, int columna, std::string id, int cantidad);

    std::string obtenerSimbolo() override;

    //int devolverCantidad();

    void mostrar() override;

};

#endif //TP2_CRUZ_H
