#ifndef TP2_SER_H
#define TP2_SER_H
#include "objeto.h"

class Ser : public Objeto{
protected:
	int vida;
	int ataque;
	int armadura;
	int energia;
public:
	Ser(int fila, int columna, std::string id, int vida, int ataque, int armadura, int energia);

	virtual void mostrar();

	virtual void atacar();
	virtual void defender();

};


#endif //TP2_SER_H
