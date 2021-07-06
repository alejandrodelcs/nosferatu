#include "Vanesa.h"
Vanesa::Vanesa(int fila, int columna){
    this->fila=fila;
    this->col=columna;
    simbolo="W";
    cantidad = 1;
}
std::string Vanesa::dar_simbolo(){
    return simbolo;
}
int Vanesa::dar_cantidad() {
    return cantidad;
}
int Vanesa::dar_fila(){
    return fila;
}
int Vanesa::dar_col(){
    return col;
}
void Vanesa::mostrar(){
    std::cout<<"Vanesa Helsin"<<std::endl;
}