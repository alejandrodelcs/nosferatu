#include "estaca.h"

estaca::estaca(int fila, int col) {
    this->fila=fila;
    this->col=col;
    simbolo="e";
    cantidad=1;
}
std::string estaca::dar_simbolo() {
    return simbolo;
}
int estaca::dar_cantidad() {
    return cantidad;
}
int estaca::dar_fila(){
    return fila;
}
int estaca::dar_col(){
    return col;
}
void estaca::mostrar() {
    std::cout<<"estaca"<<std::endl;
}