#ifndef TP2_VAMPIRO_H
#define TP2_VAMPIRO_H

#include "monstruo.h"

class Vampiro : public Monstruo {
public:
    Vampiro(int fila, int columna, std::string id, int vida, int ataque, int armadura, int energia);

    void mostrar();

    virtual std::string obtenerSimbolo();

    virtual int obtenerFila();

    virtual int obtenerColumna();

    virtual std::string obtenerId();
    
	virtual void atacar();
	
	virtual void defender();

};

#endif //TP2_VAMPIRO_H
