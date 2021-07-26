#ifndef NOSFERATU_ESTADO_H
#define NOSFERATU_ESTADO_H
#include "constantes.h"
#include <string>

class Estado
{
private:
    std::string lineaArchivo;
    std::string coordenada;
    std::string nombre;
    std::string identificador;
    int cantidad;
    int posicionX;
    int posicionY;
private:
    //PRE:
    //POST:
    void nombreObjeto();

    //PRE:
    //POST:
    void coordenadaObjeto();

    //PRE:
    //POST:
    void validarNombreObjeto();

    //PRE:
    //POST:
    void validarCantidadObjeto();

    //PRE:
    //POST:
    void validarPosicionX();

    //PRE:
    //POST:
    void validarPosicionY();

    //PRE:
    //POST:
    void validarIdentificador();

public:

    //PRE:
    //POST:
    Estado();

    //PRE:
    //POST:
    void leerLineaArchivo(std::string linea);

    //PRE:
    //POST: devuelve el nombre del objeto, si es humano cazavampiro devuelve CV
    std::string devolverNombreObjeto();

    //PRE:
    //POST: devuelve la cantidad del objeto, en caso de que no poseer con dicho atributo devuelve 0
    int devolverCantidad();

    //PRE:
    //POST: devuelve la coordenada en X del objeto
    int devolverPosx();

    //PRE:
    //POST: devuelve la coordenada en Y del objeto
    int devolverPosy();

    //PRE:
    //POST:
    std::string devolverId();

};

#endif //NOSFERATU_ESTADO_H
