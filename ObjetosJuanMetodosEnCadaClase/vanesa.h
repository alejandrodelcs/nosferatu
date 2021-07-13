#ifndef TP2_VANESA_H
#define TP2_VANESA_H

#include "cazavampiro.h"

class Vanesa : public Cazavampiro {
public:
    Vanesa(int fila, int columna, std::string id, int vida, int ataque, int armadura, int energia);

    void mostrar();

    std::string obtenerSimbolo();

    int obtenerFila();

    int obtenerColumna();

    std::string obtenerId();
    
	void atacar();
	
	void defender();

};

#endif //TP2_VANESA_H
