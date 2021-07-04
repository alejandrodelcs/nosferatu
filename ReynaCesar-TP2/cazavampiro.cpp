
#include "cazavampiro.h"
cazavampiro::cazavampiro(int fila, int col){
    this->fila=fila;
    this->col=col;
    simbolo="H";
    cantidad = 1;
}
std::string cazavampiro::dar_simbolo(){
    return  simbolo;
}
void cazavampiro::mostrar(){
    std::cout<<"Vanesa Helsin"<<std::endl;
}
int cazavampiro::dar_cantidad() {
    return cantidad;
}
int cazavampiro::dar_fila(){
    return fila;
}
int cazavampiro::dar_col(){
    return col;
}
cazavampiro::cazavampiro() {}
