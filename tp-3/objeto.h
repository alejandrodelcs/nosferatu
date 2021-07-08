#ifndef TP2_OBJETO_H
#define TP2_OBJETO_H
#include "iostream"
#include <string>
class Objeto{
protected:
    int fila;
    int columna;
    int cantidad;
public:
    std::string simbolo;
    //POST:constructor de objeto
    Objeto();

    //POST:Muestra informacion del objeto
    virtual void mostrar() = 0;

    //POST:da el simbolo del objeto
    virtual std::string devolverSimbolo()=0;

    //POST:da la cantidad del objeto
    virtual int devolverCantidad()=0;

    //POST:da la fila del objeto
    virtual int devolverFila()=0;

    //POST:da la columna del objeto
    virtual int devolverColumna()=0;

    virtual ~Objeto() = default;
};
#endif //TP2_OBJETO_H
