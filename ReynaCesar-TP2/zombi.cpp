#include "zombie.h"

zombi::zombi(int fila , int col) {
    this->fila=fila;
    this->col=col;
    simbolo="z";
    cantidad = 1;
}
std::string zombi::dar_simbolo(){
    return simbolo;
}
int zombi::dar_cantidad() {
    return cantidad;
}
int zombi::dar_fila(){
    return fila;
}
int zombi::dar_col(){
    return col;
}
void zombi::mostrar() {
    std::cout<<"el zombi"<<std::endl;
}