#ifndef TP2_VAMPIRO_H
#define TP2_VAMPIRO_H
#include "monstruo.h"

class vampiro : public monstruo{
public:
    vampiro(int fila,int col);
    vampiro();
    std::string dar_simbolo();
    int dar_cantidad();
    int dar_fila();
    int dar_col();
    void mostrar();
};

#endif //TP2_VAMPIRO_H
