#ifndef TP2_ESTACA_H
#define TP2_ESTACA_H
#include "elemento.h"

class estaca : public elemento{
public:
    estaca(int fila,int col);
    std::string dar_simbolo();
    int dar_cantidad();
    int dar_fila();
    int dar_col();
    void mostrar();
};
#endif //TP2_ESTACA_H
