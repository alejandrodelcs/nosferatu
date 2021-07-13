#ifndef TP2_AGUA_H
#define TP2_AGUA_H

#include "elemento.h"

class Agua : public Elemento {
public:
    Agua(int fila, int columna, std::string id, int cantidad);

    void mostrar();

    int obtenerCantidad();

	std::string obtenerSimbolo();

    int obtenerFila();

    int obtenerColumna();

    std::string obtenerId();
};

#endif //TP2_AGUA_H
