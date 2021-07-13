#ifndef TP2_ESCOPETA_H
#define TP2_ESCOPETA_H

#include "elemento.h"

class Escopeta : public Elemento {
public:
    Escopeta(int fila, int columna, std::string id, int cantidad);

    void mostrar();

    int obtenerCantidad();

	std::string obtenerSimbolo();

    int obtenerFila();

    int obtenerColumna();

    std::string obtenerId();
};

#endif //TP2_ESCOPETA_H
