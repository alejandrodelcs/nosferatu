#include "vampirella.h"

Vampirella::Vampirella(int fila, int columna, std::string id) : Vampiro(fila, columna, id){
    this->fila = fila;
    this->columna = columna;
    this->simbolo = "V";
    this->id = id;
    this->vida = asignarVida();
    this->ataque = asignarAtaque();
    this->energia = asignarEnergia();
    this->armadura = asignarArmdura();
}

std::string Vampirella::obtenerSimbolo() {
    return simbolo;
}


void Vampirella::mostrar() {
    std::cout << "Vampirella: "<< "Fila: " << fila <<" Columna: "<< columna <<std::endl;
    std::cout << "Vida "<<vida;
    std::cout << " Energia "<< energia;
    std::cout << " Armadura " << armadura << std::endl;

}

bool Vampirella::tomar_objeto(std::string objeto, int cant) {
    bool tomo_objeto=false;
    if(objeto=="e"){
        tomo_objeto=true;
    }
    return tomo_objeto;
}
bool Vampirella::esta_en_rango(int fila, int col) {
    return((fila == this->fila-1 && col == this->columna) ||
           (fila == this->fila && col == this->columna-1) ||
           (fila == this->fila+1 && col == this->columna) ||
           (fila == this->fila && col == this->columna+1));
}
int Vampirella::atacar(int fila, int col, std::string simbolo) {
    int danio=0;
    if(esta_en_rango(fila,col))danio=ataque;
    else if(energia<4)std::cout<<"energia insuficiente"<<std::endl;
    return danio;
}
void Vampirella::defender(){
    if(energia<5)std::cout<<"energia insuficiente"<<std::endl;
    else {
    }
}
void Vampirella::recuperarEnergia(){
    if (energia + 6 >20) energia=20;
    else energia+=4;
}
void Vampirella::recibir_ataque(int ataque){
    if(armadura==1)ataque=ataque*0.9;
    else if(armadura==2)ataque=ataque*0.8;
    else if(armadura>2)ataque=ataque*0.2;
    vida -=ataque;
}
