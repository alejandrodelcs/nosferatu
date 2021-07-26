#ifndef TP2_NOSFERATU_H
#define TP2_NOSFERATU_H

#include "vampiro.h"

class Nosferatu : public Vampiro {
public:
    Nosferatu(int fila, int columna, const std::string& id);

    std::string obtenerSimbolo();

    void mostrar();

    int atacar(int fila, int col,std::string simbolo);
    void defender();
    bool tomar_objeto(std::string elemento,int cant);
    bool esta_en_rango(int fila,int col);
    void recuperarEnergia();
    void recibir_ataque(int ataque);
    int obtener_energia();
};

#endif //TP2_NOSFERATU_H
