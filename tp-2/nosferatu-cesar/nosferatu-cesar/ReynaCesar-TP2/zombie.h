#ifndef TP2_ZOMBIE_H
#define TP2_ZOMBIE_H
#include "monstruo.h"

class zombi : public monstruo{
public:
    zombi(int fila, int col);
    std::string dar_simbolo();
    int dar_cantidad();
    int dar_fila();
    int dar_col();
    void mostrar();
};
#endif //TP2_ZOMBIE_H