#ifndef TP2_BALAS_H
#define TP2_BALAS_H

#include "elemento.h"

class Balas : public Elemento {
public:
    Balas(int fila, int columna, std::string id, int cantidad);

    void mostrar();

    int obtenerCantidad();

	std::string obtenerSimbolo();

    int obtenerFila();

    int obtenerColumna();

    std::string obtenerId();
};

#endif //TP2_BALAS_H
