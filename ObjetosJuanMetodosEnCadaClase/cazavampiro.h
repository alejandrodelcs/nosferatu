#ifndef TP2_CAZAVAMPIRO_H
#define TP2_CAZAVAMPIRO_H

#include "humano.h"

class Cazavampiro : public Humano {
public:
    Cazavampiro(int fila, int columna, std::string id, int vida, int ataque, int armadura, int energia);

    void mostrar();

    virtual std::string obtenerSimbolo();

    virtual int obtenerFila();

    virtual int obtenerColumna();

    virtual std::string obtenerId();
    
	virtual void atacar();
	
	virtual void defender();
};

#endif //TP2_CAZAVAMPIRO_H
