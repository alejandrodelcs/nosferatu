#ifndef TP2_MONSTRUO_H
#define TP2_MONSTRUO_H
#include "ser.h"

class Monstruo : public Ser{
public:
    Monstruo(int fila, int columna, std::string id, int vida, int ataque, int armadura, int energia);

    void mostrar();

    virtual std::string obtenerSimbolo();

    virtual int obtenerFila();

    virtual int obtenerColumna();

    virtual std::string obtenerId();
    
	virtual void atacar();
	
	virtual void defender();
};


#endif //TP2_MONSTRUO_H