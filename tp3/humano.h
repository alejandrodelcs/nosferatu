#ifndef TP2_HUMANO_H
#define TP2_HUMANO_H

#include "ser.h"

class Humano : public Ser {
private:
    bool escopeta;
    int municion;
    int agua;
public:
    Humano(int fila, int columna, std::string id);

    std::string obtenerSimbolo();

    void mostrar();

    int atacar(int fila, int col,std::string simbolo);

    void defender();

    bool esta_en_rango(int fila,int col);

    bool tomar_objeto(std::string objeto, int cant);

    void recuperarEnergia();

    void recibir_ataque(int ataque);

private:
    bool rango_escopeta(int fila,int col);
};

#endif //TP2_HUMANO_H
