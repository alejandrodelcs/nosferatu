#include "vampiro.h"

Vampiro::Vampiro(int fila, int columna, std::string id) {
    this->fila = fila;
    this->columna = columna;
    this->simbolo = "v";
    this->id = id;
    this->vida = asignarVida();
    this->ataque = asignarAtaque();
    this->energia = asignarEnergia();
    this->armadura = asignarArmdura();
}

std::string Vampiro::obtenerSimbolo() {
    return simbolo;
}


void Vampiro::mostrar() {
    std::cout << "vampiro " << fila<<" "<< columna<<std::endl;
    std::cout<< "armadura "<<armadura<<std::endl;
    std::cout<< "energia "<<energia<<std::endl;
}

bool Vampiro::tomar_objeto(std::string objeto, int cant) {
    bool tomo_objeto=false;
    if(objeto=="e"){
        tomo_objeto=true;
    }
    return tomo_objeto;
}
bool Vampiro::esta_en_rango(int fila, int col) {
    return((fila == this->fila-1 && col == this->columna) ||
           (fila == this->fila && col == this->columna-1) ||
           (fila == this->fila+1 && col == this->columna) ||
           (fila == this->fila && col == this->columna+1));
}
int Vampiro::atacar(int fila, int col, std::string simbolo) {
    int danio=0;
    if(esta_en_rango(fila,col))danio=ataque;
    else if(energia<4)std::cout<<"energia insuficiente"<<std::endl;
    return danio;
}
void Vampiro::defender() {
    if(energia<4)std::cout<<"energia insuficiente"<<std::endl;
    else {
        energia -=4;
        armadura +=1;
    }
}
void Vampiro::recuperarEnergia(){
    if (energia + 4 >20) energia=20;
    else energia+=4;
}
void Vampiro::recibir_ataque(int ataque){
    if(armadura==1)ataque=ataque*0.9;
    else if(armadura==2)ataque=ataque*0.8;
    else if(armadura>2)ataque=ataque*0.2;
    vida -=ataque;
}
