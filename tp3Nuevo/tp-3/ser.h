#ifndef TP2_SER_H
#define TP2_SER_H
#include "objeto.h"

class Ser : public Objeto{
protected:
	int vida;
	int ataque; //int fuerza
	//int armadura;
	//int energia;
public:
    Ser(){};
	int asignarVida();
	int asignarAtaque();
	int obtenerVida();
	int obtenerAtaque();
	virtual void atacar() = 0;
	virtual void defender() = 0;
	virtual bool esta_en_rango(int fila,int col) = 0;
	virtual bool tomar_objeto(std::string elemento,int cant)=0;
	//virtual int recuperarEnergia() = 0;
};

#endif //TP2_SER_H
