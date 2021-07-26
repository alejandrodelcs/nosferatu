#ifndef TP2_ZOMBIE_H
#define TP2_ZOMBIE_H

#include "monstruo.h"

class Zombi : public Monstruo {
public:
    Zombi(int fila, int columna, std::string id);

    std::string obtenerSimbolo();

    void mostrar();
    int atacar(int fila, int col,std::string simbolo);
    void defender();
    bool tomar_objeto(std::string objeto,int cant);
    bool esta_en_rango(int fila,int col);
    void recuperarEnergia();
    void recibir_ataque(int ataque);
};

#endif //TP2_ZOMBIE_H
