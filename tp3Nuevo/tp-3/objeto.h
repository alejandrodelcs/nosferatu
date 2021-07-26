#ifndef TP2_OBJETO_H
#define TP2_OBJETO_H
#include "iostream"
#include <string>


class Objeto{
protected:
    int fila;
    int columna;
    std::string id;

public:
    std::string simbolo;

    //POST:Muestra informacion del objeto
    virtual void mostrar() = 0;

    //POST:da el simbolo del objeto
    virtual std::string obtenerSimbolo() = 0;

    //POST:da la fila del objeto
    int obtenerFila();

    //POST:da la columna del objeto
    int obtenerColumna();

    std::string obtenerId();

    void asignarFila(int fila);

    void asignarColumna(int columna);

    virtual ~Objeto() = default;
};
#endif //TP2_OBJETO_H
