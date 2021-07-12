#ifndef TP2_NOSFERATU_H
#define TP2_NOSFERATU_H

#include "vampiro.h"

class Nosferatu : public Vampiro {
public:
    Nosferatu(int fila, int columna, std::string id, int vida, int ataque, int armadura, int energia);


    void mostrar() override;
};

#endif //TP2_NOSFERATU_H
