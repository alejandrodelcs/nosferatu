#ifndef TP2_VANESA_H
#define TP2_VANESA_H

#include "cazavampiro.h"

class Vanesa : public Cazavampiro {
private:
    bool escopeta;
    int municion;
    int estacas;
    int agua;
    int cruces;
public:
    Vanesa(int fila, int columna, std::string id);

    std::string obtenerSimbolo();

    void mostrar();

    bool esta_en_rango(int fila,int col);

    bool tomar_objeto(std::string objeto,int cant);

    void recuperarEnergia();

    void recibir_ataque(int ataque);

    int atacar(int fila, int col,std::string simbolo);

    void defender();

private:
    bool rango_escopeta(int fila,int col);
    bool rango_agua(int fila,int col);
    bool rango_estaca(int fila,int col);
};

#endif //TP2_VANESA_H
