#ifndef TP2_ZOMBIE_H
#define TP2_ZOMBIE_H

#include "monstruo.h"

class zombi : public Monstruo {
public:
    zombi(int fila, int columna, std::string id, int vida, int ataque, int armadura, int energia);

    void mostrar();
};

#endif //TP2_ZOMBIE_H
