#ifndef TP2_VAMPIRO_H
#define TP2_VAMPIRO_H

#include "monstruo.h"

class Vampiro : public Monstruo {
public:
    Vampiro(int fila, int columna, std::string id, int vida, int ataque, int armadura, int energia);


    void mostrar();

};

#endif //TP2_VAMPIRO_H
