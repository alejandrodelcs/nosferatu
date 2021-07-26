#ifndef TP2_NOSFERATU_H
#define TP2_NOSFERATU_H

#include "vampiro.h"

class Nosferatu : public Vampiro {
public:
    Nosferatu(int fila, int columna, const std::string& id);

    std::string obtenerSimbolo();

    void mostrar();

    void atacar(){};
    void defender(){};
    bool tomar_objeto(std::string elemento,int cant);
    bool esta_en_rango(int fila,int col);
};

#endif //TP2_NOSFERATU_H
