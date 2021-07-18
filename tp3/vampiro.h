#ifndef TP2_VAMPIRO_H
#define TP2_VAMPIRO_H

#include "monstruo.h"

class Vampiro : public Monstruo {
public:
    Vampiro(int fila, int columna, std::string id);

    std::string obtenerSimbolo();

    void mostrar();

    void atacar(){};
    void defender(){};


};

#endif //TP2_VAMPIRO_H
