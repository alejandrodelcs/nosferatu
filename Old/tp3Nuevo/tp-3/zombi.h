#ifndef TP2_ZOMBIE_H
#define TP2_ZOMBIE_H

#include "monstruo.h"

class Zombi : public Monstruo {
public:
    Zombi(int fila, int columna, std::string id);

    std::string obtenerSimbolo();

    void mostrar();
    void atacar(){};
    void defender(){};

};

#endif //TP2_ZOMBIE_H
