#ifndef TP2_SER_H
#define TP2_SER_H
#include "objeto.h"

class Ser : public Objeto{
protected:
	int vida;
	int ataque;
public:
	//Ser(int fila, int columna, std::string id, int vida, int ataque);
	virtual void atacar() = 0;
	virtual void defender() = 0;
};

#endif //TP2_SER_H
