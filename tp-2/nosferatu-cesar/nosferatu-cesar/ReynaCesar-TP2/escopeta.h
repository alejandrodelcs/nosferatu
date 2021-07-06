#ifndef TP2_ESCOPETA_H
#define TP2_ESCOPETA_H
#include "elemento.h"

class escopeta : public elemento{
public:
    escopeta(int fila,int col);
    std::string dar_simbolo();
    int dar_cantidad();
    int dar_fila();
    int dar_col();
    void mostrar();
};
#endif //TP2_ESCOPETA_H
