#ifndef TP2_ESTACA_H
#define TP2_ESTACA_H

#include "elemento.h"

class Estaca : public Elemento {
public:
    Estaca(int fila, int columna, std::string id, int cantidad);

    void mostrar();
};

#endif //TP2_ESTACA_H
