#include "nosferatu.h"

Nosferatu::Nosferatu(int fila, int columna, const std::string& id) : Vampiro(fila, columna, id){
    this->fila = fila;
    this->columna = columna;
    this->simbolo = "N";
    this->id = id;
    this->vida = asignarVida();
    this->ataque = asignarAtaque();
}

std::string Nosferatu::obtenerSimbolo() {
    return simbolo;
}


void Nosferatu::mostrar() {
    std::cout << "Nosferatu" << std::endl;
}

bool Nosferatu::tomar_objeto(std::string objeto, int cant) {
    bool tomo_objeto=false;
    if(objeto=="e"){
        tomo_objeto=true;
    }
    return tomo_objeto;
}
bool Nosferatu::esta_en_rango(int fila, int col) {
    return(fila<=this->fila+2 && col<=this->columna+2);
}

int Nosferatu::atacar(int fila, int col, std::string simbolo) {
    int danio=0;
    if(energia<10)std::cout<<"energia insuficiente"<<std::endl;
    else if(esta_en_rango(fila,col))danio=ataque;
    return danio;
}
void Nosferatu::recibir_ataque(int ataque) {
    if(armadura==1)ataque=ataque*0.9;
    else if(armadura==2)ataque=ataque*0.8;
    else if(armadura>2)ataque=ataque*0.2;
    vida -=ataque;
}
void Nosferatu::recuperarEnergia() {
    if (energia + 10 >20) energia=20;
    else energia+=10;
}
void Nosferatu::defender() {

}