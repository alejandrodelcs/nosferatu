#ifndef NOSFERATU_TABLERO_H
#define NOSFERATU_TABLERO_H
#include "objeto.h"

class Tablero: public Objeto{
protected:
    Objeto ***pObjeto;
    int abscisa;
    int ordenada;
public:
    Tablero();
    Tablero(int fila, int columna);
    void imprimirTablero();
    ~Tablero() override;
};

#endif //NOSFERATU_TABLERO_H
