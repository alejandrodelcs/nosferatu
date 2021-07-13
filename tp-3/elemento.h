#ifndef TP2_ELEMENTO_H
#define TP2_ELEMENTO_H
#include "objeto.h"

class Elemento : public Objeto{
protected:
	int cantidad;
public:
	//Elemento(int fila, int columna, int cantidad, std::string id);
	virtual int obtenerCantidad();
};

#endif //TP2_ELEMENTO_H
