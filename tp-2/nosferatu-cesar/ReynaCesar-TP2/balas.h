#ifndef TP2_BALAS_H
#define TP2_BALAS_H
#include "elemento.h"
class balas : public elemento{
public:
    balas(int fila,int col,int cant);
    std::string dar_simbolo();
    int dar_cantidad();
    int dar_fila();
    int dar_col();
    void mostrar();
};
#endif //TP2_BALAS_H
