#ifndef TP_3_IDE_H
#define TP_3_IDE_H
#include "constantes.h"
#include "ABB.h"
#include "tablero.h"

class IDE{
private:
    ABB<string, Objeto*>* diccionarioPersonajes;

public:
    string dar_codigo(int opcion);
};
#endif //TP_3_IDE_H
