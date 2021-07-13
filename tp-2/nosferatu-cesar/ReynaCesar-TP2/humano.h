#ifndef TP2_HUMANO_H
#define TP2_HUMANO_H
#include "ser.h"

class humano : public  ser{
public:
    humano(int ancho,int alto);
    humano();
    std::string dar_simbolo();
    int dar_cantidad();
    int dar_fila();
    int dar_col();
    void mostrar();
};

#endif //TP2_HUMANO_H
