#ifndef TP2_AGUA_H
#define TP2_AGUA_H
#include "elemento.h"

class agua : public elemento{
public:
    agua(int fila, int col,  int cant);
    std::string dar_simbolo();
    int dar_cantidad();
    int dar_fila();
    int dar_col();
    void mostrar();
};
#endif //TP2_AGUA_H
