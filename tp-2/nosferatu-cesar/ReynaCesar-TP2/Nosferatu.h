#ifndef TP2_NOSFERATU_H
#define TP2_NOSFERATU_H
#include "vampiro.h"
class Nosferatu : public vampiro{
public:
    Nosferatu(int fila,int col);
    std::string dar_simbolo();
    int dar_cantidad();
    int dar_fila();
    int dar_col();
    void mostrar();
};
#endif //TP2_NOSFERATU_H
