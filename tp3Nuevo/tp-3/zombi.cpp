#include "zombi.h"

Zombi::Zombi(int fila, int columna, std::string id) {
    this->fila = fila;
    this->columna = columna;
    this->simbolo = "z";
    this->id = id;
    this->vida = asignarVida();
    this->ataque = asignarAtaque();
    this->energia = asignarEnergia();
    this->armadura = asignarArmdura();
}

std::string Zombi::obtenerSimbolo() {
    return simbolo;
}


void Zombi::mostrar() {
    std::cout << "el zombi " << fila<<" "<< columna<<std::endl;
    std::cout<< "armadura "<<armadura<<std::endl;
    std::cout<< "energia "<<energia<<std::endl;
}
bool Zombi::tomar_objeto(std::string objeto, int cant) {
    bool tomo_objeto=false;
    if(objeto=="a"){
        tomo_objeto=true;
    }
    return tomo_objeto;
}
bool Zombi::esta_en_rango(int fila, int col) {
    return((fila == this->fila-1 && col == this->columna) ||
           (fila == this->fila && col == this->columna-1) ||
           (fila == this->fila+1 && col == this->columna) ||
           (fila == this->fila && col == this->columna+1));
}
int Zombi::atacar(int fila, int col, std::string simbolo) {
    int danio=0;
    if (energia<5)std::cout<<"energia insuficiente"<<std::endl;
    else if(esta_en_rango(fila,col))danio=ataque;
    return danio;
}
void Zombi::recuperarEnergia() {
    if (energia + 5 >20) energia=20;
    else energia+=4;
}
void Zombi::defender() {
    if(energia<2)std::cout<<"energia insuficiente"<<std::endl;
    else {
        vida +=20;
    }
}
void Zombi::recibir_ataque(int ataque) {
    if(armadura==1)ataque=ataque*0.9;
    else if(armadura==2)ataque=ataque*0.8;
    else if(armadura>2)ataque=ataque*0.2;
    vida -=ataque;
}
