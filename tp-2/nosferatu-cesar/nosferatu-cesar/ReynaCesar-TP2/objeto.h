#ifndef TP2_OBJETO_H
#define TP2_OBJETO_H
#include "iostream"
#include <string>
class objeto{
protected:
    int fila;
    int col;
    int cantidad;
    std::string simbolo;
public:
    //POST:constructor de objeto
    objeto();
    //POST:Muestra informacion del objeto
    virtual void mostrar()=0;
    //POST:da el simbolo del objeto
    virtual std::string dar_simbolo()=0;
    //POST:da la cantidad del objeto
    virtual int dar_cantidad()=0;
    //POST:da la fila del objeto
    virtual int dar_fila()=0;
    //POST:da la columna del objeto
    virtual int dar_col()=0;
};
#endif //TP2_OBJETO_H
