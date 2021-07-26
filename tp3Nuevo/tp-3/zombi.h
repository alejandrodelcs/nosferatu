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
    bool tomar_objeto(std::string objeto,int cant);
    bool esta_en_rango(int fila,int col);
};

#endif //TP2_ZOMBIE_H
