#ifndef TP2_OBJETO_H
#define TP2_OBJETO_H
#include "iostream"
#include <string>


class Objeto{
protected:
    int fila;
    int columna;
    std::string id;
    std::string simbolo;
public:

    Objeto(int fila, int columna, std::string id);

    //POST:Muestra informacion del objeto
    virtual void mostrar();

    //POST:da el simbolo del objeto
    virtual std::string obtenerSimbolo();

    //POST:da la fila del objeto
    virtual int obtenerFila();

    //POST:da la columna del objeto
    virtual int obtenerColumna();

    virtual std::string obtenerId();
    
};
#endif //TP2_OBJETO_H
