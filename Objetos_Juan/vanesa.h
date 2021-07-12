#ifndef TP2_VANESA_H
#define TP2_VANESA_H

#include "cazavampiro.h"

class Vanesa : public Cazavampiro {
public:
    Vanesa(int fila, int columna, std::string id, int vida, int ataque, int armadura, int energia);

    void mostrar();

};

#endif //TP2_VANESA_H
