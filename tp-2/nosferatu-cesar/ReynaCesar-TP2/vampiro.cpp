#include "vampiro.h"

vampiro::vampiro(int fila,int col){
    this->fila=fila;
    this->col=col;
    simbolo="v";
    cantidad = 1;
}
std::string vampiro::dar_simbolo(){
    return simbolo;
}
int vampiro::dar_cantidad() {
    return cantidad;
}
int vampiro::dar_fila(){
    return fila;
}
int vampiro::dar_col(){
    return col;
}
void vampiro::mostrar(){
    std::cout<<"vampiro"<<std::endl;
}

vampiro::vampiro() {}
