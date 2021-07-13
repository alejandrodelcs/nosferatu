#ifndef TP2_ELEMENTO_H
#define TP2_ELEMENTO_H
#include "objeto.h"

class Elemento : public Objeto{
protected:
	int cantidad;
public:
	Elemento(int fila, int columna, std::string id, int cantidad);

	virtual void mostrar();

	virtual int obtenerCantidad();

	virtual std::string obtenerSimbolo();

    virtual int obtenerFila();

    virtual int obtenerColumna();

    virtual std::string obtenerId();

};

#endif //TP2_ELEMENTO_H
