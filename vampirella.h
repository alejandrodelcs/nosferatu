#ifndef TP2_VAMPIRELLA_H
#define TP2_VAMPIRELLA_H
#include "vampiro.h"

class Vampirella : public Vampiro {
public:
    Vampirella(int fila, int columna, std::string id, int vida, int ataque);

    std::string obtenerSimbolo();

    void mostrar();

};

#endif //TP2_VAMPIRELLA_H
