#ifndef TP2_VANESA_H
#define TP2_VANESA_H
#include "cazavampiro.h"
class Vanesa : public cazavampiro{
public:
    Vanesa(int fila, int columna);
    std::string dar_simbolo();
    int dar_cantidad();
    int dar_fila();
    int dar_col();
    void mostrar();
};
#endif //TP2_VANESA_H
