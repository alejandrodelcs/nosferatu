#ifndef TP2_HUMANO_H
#define TP2_HUMANO_H

#include "ser.h"

class Humano : public Ser {
public:
    Humano(int fila, int columna, std::string id, int vida, int ataque, int armadura, int energia);

    void mostrar();

};

#endif //TP2_HUMANO_H
