#ifndef TP2_VAMPIRELLA_H
#define TP2_VAMPIRELLA_H
#include "vampiro.h"

class Vampirella : public Vampiro {
public:
    Vampirella(int fila, int columna, std::string id);

    std::string obtenerSimbolo();

    void mostrar();

    void atacar(){};
    void defender(){};


};

#endif //TP2_VAMPIRELLA_H
