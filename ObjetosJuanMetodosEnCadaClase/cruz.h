#ifndef TP2_CRUZ_H
#define TP2_CRUZ_H

#include "elemento.h"

class Cruz : public Elemento {
public:
    Cruz(int fila, int columna, std::string id, int cantidad);

    void mostrar();

    int obtenerCantidad();

	std::string obtenerSimbolo();

    int obtenerFila();

    int obtenerColumna();

    std::string obtenerId();
};

#endif //TP2_CRUZ_H
