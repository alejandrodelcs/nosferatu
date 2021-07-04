#include "Vampirella.h"
Vampirella::Vampirella(int fila,int col){
    this->fila=fila;
    this->col=col;
    simbolo="V";
    cantidad = 1;
}
std::string Vampirella::dar_simbolo(){
    return simbolo;
}
int Vampirella::dar_cantidad() {
    return cantidad;
}
int Vampirella::dar_fila(){
    return fila;
}
int Vampirella::dar_col(){
    return col;
}
void Vampirella::mostrar(){
    std::cout<<"Vampirella"<<std::endl;
}