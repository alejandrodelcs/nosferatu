#ifndef TP2_CAZAVAMPIRO_H
#define TP2_CAZAVAMPIRO_H

#include "humano.h"

class Cazavampiro : public Humano {
private:
    bool escopeta;
    int municion;
    int estacas;
    int agua;
public:
    Cazavampiro(int fila, int columna, std::string id);

    std::string obtenerSimbolo();

    void mostrar();

    bool esta_en_rango(int fila,int col);

    bool tomar_objeto(std::string objeto,int cant);
private:
    bool rango_escopeta(int fila,int col);
    bool rango_agua(int fila,int col);
    bool rango_estaca(int fila,int col);
};

#endif //TP2_CAZAVAMPIRO_H
