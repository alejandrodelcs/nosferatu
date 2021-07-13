#ifndef NOSFERATU_ESTADO_H
#define NOSFERATU_ESTADO_H
#include "constantes.h"
#include <string>

class Estado
{
private:
    std::string lineaArchivo;
    std::string coordenada, nombreObjeto;
public:
    //PRE:
    //POST: crea linea a linea el archivo
    explicit Estado(const std::string& lineaArchivo);

    //PRE:
    //POST: devuelve el nombre del objeto, si es humano cazavampiro devuelve CV
    std::string devolverNombre();

    //PRE:
    //POST: devuelve la cantidad del objeto, en caso de que no poseer con dicho atributo devuelve 0
    int devolverCantidad();

    //PRE:
    //POST: devuelve la coordenada en X del objeto
    int devolverPosx();

    //PRE:
    //POST: devuelve la coordenada en Y del objeto
    int devolverPosy();

};

#endif //NOSFERATU_ESTADO_H
