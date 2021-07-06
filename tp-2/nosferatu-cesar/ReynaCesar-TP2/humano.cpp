#include "humano.h"
humano::humano(int ancho,int alto){
    this->fila=ancho;
    this->col=alto;
    simbolo="h";
    cantidad = 1;
}
std::string humano::dar_simbolo() {
    return simbolo;
}
int humano::dar_cantidad() {
    return cantidad;
}
int humano::dar_fila(){
    return fila;
}
int humano::dar_col(){
    return col;
}
void humano::mostrar(){
    std::cout<<"humano"<<std::endl;
}

humano::humano() {}
