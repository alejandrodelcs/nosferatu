#ifndef TP2_CRUZ_H
#define TP2_CRUZ_H
#include "elemento.h"

class cruz : public elemento{
public:
    cruz(int fil, int col);
    std::string dar_simbolo();
    int dar_cantidad();
    int dar_fila();
    int dar_col();
    void mostrar();
};
#endif //TP2_CRUZ_H
