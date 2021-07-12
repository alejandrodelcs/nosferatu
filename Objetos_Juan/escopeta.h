#ifndef TP2_ESCOPETA_H
#define TP2_ESCOPETA_H

#include "elemento.h"

class Escopeta : public Elemento {
public:
    Escopeta(int fila, int columna, std::string id, int cantidad);

    void mostrar();
};

#endif //TP2_ESCOPETA_H
