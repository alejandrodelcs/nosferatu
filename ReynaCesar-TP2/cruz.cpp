#include "cruz.h"

cruz::cruz(int fil, int col) {
    this->fila=fil;
    this->col=col;
    simbolo="c";
    cantidad = 1;
}
std::string cruz::dar_simbolo(){
    return  simbolo;
}
int cruz::dar_cantidad() {
    return cantidad;
}
int cruz::dar_fila(){
    return fila;
}
int cruz::dar_col(){
    return col;
}
void cruz::mostrar() {
    std::cout<<"cruz"<<std::endl;
}