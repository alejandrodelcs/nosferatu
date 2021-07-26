#ifndef TP2_VAMPIRELLA_H
#define TP2_VAMPIRELLA_H
#include "vampiro.h"

class Vampirella : public Vampiro {
public:
    Vampirella(int fila, int columna, std::string id);

    std::string obtenerSimbolo();

    void mostrar();

    int atacar(int fila,int col,std::string simbolo);
    void defender();

    bool tomar_objeto(std::string elemento,int cant);
    bool esta_en_rango(int fila, int col);
    void recuperarEnergia();
    void recibir_ataque(int ataque);
    int obtener_energia();
};

#endif //TP2_VAMPIRELLA_H
