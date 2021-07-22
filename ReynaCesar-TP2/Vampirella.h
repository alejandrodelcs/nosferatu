#ifndef TP2_VAMPIRELLA_H
#define TP2_VAMPIRELLA_H
#include "vampiro.h"

class Vampirella : public vampiro{
public:
    Vampirella(int fila,int col);
    std::string dar_simbolo();
    int dar_cantidad();
    int dar_fila();
    int dar_col();
    void mostrar();

};

#endif //TP2_VAMPIRELLA_H
