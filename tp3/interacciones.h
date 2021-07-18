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
//private:
//	Tablero* tablero;
//	ABB<std::string, Objeto*>* diccionarioPersonajes;
private:
    bool validarMonstruo(const std::string& id);
    bool validarElemento(const std::string& id);
    bool validarSer(const std::string& id);
    void decidirObjeto(const std::string& id, int fila, int columna,const std::string& nombre,int cantidad, ABB<std::string, Objeto*> *diccionarioPersonajes, Tablero* tablero);
    void crearElemento(const std::string& id, int fila, int columna, const std::string& nombre, int cantidad, ABB<std::string, Objeto*> *diccionarioPersonajes, Tablero* tablero);
    void crearMounstruo(const std::string& id, int fila, int columna, const std::string& nombre, ABB<std::string, Objeto*> *diccionarioPersonajes, Tablero* tablero);
    void crearSer(const std::string& id, int fila, int columna, const std::string& nombre, ABB<std::string, Objeto*> *diccionarioPersonajes, Tablero* tablero);


public:
    Interacciones(Tablero* tablero, ABB<std::string, Objeto*>* diccionarioPersonajes);
    //PRE: el tablero(matriz) debe existir
    //POST: devuelve el tablero con objetos
    void cargarMatriz(Tablero* tablero, ABB<std::string, Objeto*>* diccionarioPersonajes);
    //~Interacciones();

};


#endif //NOSFERATU_INTERACCIONES_H
