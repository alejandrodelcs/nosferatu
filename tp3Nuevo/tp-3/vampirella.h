#ifndef TP2_VAMPIRELLA_H
#define TP2_VAMPIRELLA_H
#include "vampiro.h"

class Vampirella : public Vampiro {
public:
    Vampirella(int fila, int columna, std::string id);

    std::string obtenerSimbolo();

    void mostrar();

    void atacar(){};
    void defender(){};

    bool tomar_objeto(std::string elemento,int cant);
    bool esta_en_rango(int fila, int col);

};

#endif //TP2_VAMPIRELLA_H
