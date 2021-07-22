#include "Nosferatu.h"

Nosferatu::Nosferatu(int fila,int col){
    this->fila=fila;
    this->col=col;
    simbolo="N";
    cantidad = 1;
}
std::string Nosferatu::dar_simbolo() {
    return simbolo;
}
int Nosferatu::dar_cantidad() {
    return cantidad;
}
int Nosferatu::dar_fila(){
    return fila;
}
int Nosferatu::dar_col(){
    return col;
}
void Nosferatu::mostrar(){
    std::cout<<"Nosferatu"<<std::endl;
}