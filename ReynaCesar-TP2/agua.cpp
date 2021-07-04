#include "agua.h"

agua::agua(int fila, int col, int cant) {
    this->fila=fila;
     this->col=col;
    cantidad=cant;
    simbolo="a";
}
std::string agua::dar_simbolo(){
    return  simbolo;
}
void agua::mostrar() {
    std::cout<<"agua"<<std::endl;
}
int agua::dar_fila(){
    return fila;
}
int agua::dar_col(){
    return col;
}
int agua::dar_cantidad() {
    return cantidad;
}