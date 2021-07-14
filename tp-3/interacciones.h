#ifndef NOSFERATU_INTERACCIONES_H
#define NOSFERATU_INTERACCIONES_H
#include <iostream>
#include <string>
#include "constantes.h"
#include "tablero.h"
#include "estado.h"
#include "objeto.h"
#include "ABB.h"

class Interacciones {
private:
    Tablero *tablero;
private:
    bool validarMonstruo(const std::string& id);
    bool validarElemento(const std::string& id);
    bool validarSer(const std::string& id);
    void decidirObjeto(const std::string& id, int fila, int columna,const std::string& nombre,int cantidad, ABB<std::string, Objeto*> *diccionarioPersonajes);
    void crearElemento(const std::string& id, int fila, int columna, const std::string& nombre, int cantidad, ABB<std::string, Objeto*> *diccionarioPersonajes);
    void crearMounstruo(const std::string& id, int fila, int columna, const std::string& nombre, ABB<std::string, Objeto*> *diccionarioPersonajes);
    void crearSer(const std::string& id, int fila, int columna, const std::string& nombre, ABB<std::string, Objeto*> *diccionarioPersonajes);


public:
    Interacciones();
    //PRE: el tablero(matriz) debe existir
    //POST: devuelve el tablero con objetos
    Tablero* cargarMatriz();
    ~Interacciones();

};


#endif //NOSFERATU_INTERACCIONES_H
