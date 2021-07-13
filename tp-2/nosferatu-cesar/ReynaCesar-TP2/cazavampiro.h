#ifndef TP2_CAZAVAMPIRO_H
#define TP2_CAZAVAMPIRO_H
#include "humano.h"

class cazavampiro : public humano{
public:
    cazavampiro();
    cazavampiro(int fila , int col);
    std::string dar_simbolo();
    int dar_cantidad();
    int dar_fila();
    int dar_col();
    void mostrar();
};
#endif //TP2_CAZAVAMPIRO_H
