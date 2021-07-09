#ifndef NOSFERATU_INTERACCIONES_H
#define NOSFERATU_INTERACCIONES_H
#include <iostream>
#include "constantes.h"
#include "tablero.h"
#include "estado.h"

class Interacciones {
protected:
public:
    Interacciones()=default;

    //PRE: el tablero(matriz) debe existir
    //POST: devuelve el tablero con objetos
    Tablero* cargarMatriz();

};


#endif //NOSFERATU_INTERACCIONES_H
