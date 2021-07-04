#include "balas.h"

balas::balas(int fila, int col, int cant) {
    this->fila=fila;
    this->col=col;
    cantidad=cant;
    simbolo="b";
}
std::string balas::dar_simbolo(){
    return simbolo;
}
int balas::dar_cantidad() {
    return cantidad;
}
int balas::dar_fila(){
    return fila;
}
int balas::dar_col(){
    return col;
}
void balas::mostrar() {
    std::cout<<"balas"<<std::endl;
}