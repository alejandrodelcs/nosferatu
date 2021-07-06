#include "escopeta.h"
escopeta::escopeta(int fila, int col) {
    this->fila=fila;
    this->col=col;
    simbolo="E";
    cantidad=1;
}
std::string escopeta::dar_simbolo() {
    return simbolo;
}
int escopeta::dar_cantidad() {
    return cantidad;
}
int escopeta::dar_fila(){
    return fila;
}
int escopeta::dar_col(){
    return col;
}
void escopeta::mostrar() {
    std::cout<<"escopeta"<<std::endl;
}