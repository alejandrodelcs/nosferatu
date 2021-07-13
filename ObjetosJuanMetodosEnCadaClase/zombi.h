#ifndef TP2_ZOMBIE_H
#define TP2_ZOMBIE_H

#include "monstruo.h"

class Zombi : public Monstruo {
public:
    Zombi(int fila, int columna, std::string id, int vida, int ataque, int armadura, int energia);

    void mostrar();

    std::string obtenerSimbolo();

    int obtenerFila();

    int obtenerColumna();

    std::string obtenerId();
    
	void atacar();
	
	void defender();
};

#endif //TP2_ZOMBIE_H
