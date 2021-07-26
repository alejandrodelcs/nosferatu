#include "cazavampiro.h"

Cazavampiro::Cazavampiro(int fila, int columna, std::string id) : Humano(fila, columna, id) {
    this->fila = fila;
    this->columna = columna;
    this->simbolo = "H";
    this->id = id;
    this->vida = asignarVida();
    this->ataque = asignarAtaque();
    this->energia = asignarEnergia();
    this->armadura = asignarArmdura();
    this-> escopeta = false;
    this-> municion = 0;
    this-> estacas = 0;
    this-> agua = 0;
    this-> cruces = 0;
}

std::string Cazavampiro::obtenerSimbolo() {
    return simbolo;
}

void Cazavampiro::mostrar() {
    std::cout << "Cazador: "<< "Fila: " << fila <<" Columna: "<< columna <<std::endl;
    std::cout << "Vida "<<vida;
    std::cout << " Energia "<< energia;
    std::cout << " Armadura " << armadura << std::endl;
    std::cout << "Agua " << agua << std::endl;
    std::cout << "Escopeta " << escopeta << std::endl;
    std::cout << "Balas " << municion << std::endl;
    std::cout << "Cruces " << cruces <<std::endl;
    std::cout << "Estacas " << estacas <<std::endl;
}

bool Cazavampiro::tomar_objeto(std::string objeto,int cant) {
    bool se_obtuvo_el_objeto=false;
    if(objeto=="E" && !escopeta){
        escopeta=true;
        se_obtuvo_el_objeto=true;
    }
    else if (objeto=="a"){
        se_obtuvo_el_objeto=true;
        agua += cant;
    }
    else if(objeto == "e"){
        estacas+=1;
        se_obtuvo_el_objeto=true;
    }
    else if(objeto == "b"){
        se_obtuvo_el_objeto=true;
        municion+=cant;
    }
    else if(objeto == "c"){
        se_obtuvo_el_objeto=true;
        cruces+=1;
    }
    return se_obtuvo_el_objeto;
}
bool Cazavampiro::rango_agua(int fila,int col) {
    return(fila<=this->fila+1 && col<=this->columna+1);
}
bool Cazavampiro::rango_escopeta(int fila, int col) {
    return(fila<=this->fila+2 && col<=this->columna+2);
}
bool Cazavampiro::rango_estaca(int fila, int col) {
    return((fila == this->fila-1 && col == this->columna) ||
           (fila == this->fila && col == this->columna-1) ||
           (fila == this->fila+1 && col == this->columna) ||
           (fila == this->fila && col == this->columna+1));
}
bool Cazavampiro::esta_en_rango(int fila, int col) {
    return true;
}
void Cazavampiro::recuperarEnergia(){
    if(energia + 8 >20) energia=20;
    else energia+=8;
}

void Cazavampiro::recibir_ataque(int ataque){
    if(armadura==1)ataque=ataque*0.9;
    else if(armadura==2)ataque=ataque*0.8;
    else if(armadura>2)ataque=ataque*0.2;
    vida -=ataque;
}

int Cazavampiro::atacar(int fila, int col,std::string simbolo){
    int opcion;
    int danio=ataque;
    std::cout<<"seleccione un arma"<<std::endl;
    std::cout<<"(1) escopeta"<<std::endl;
    std::cout<<"(2) agua"<<std::endl;
    std::cout<<"(3) estaca"<<std::endl;
    std::cin>>opcion;
    if (opcion == 1){
        if(!escopeta){
            std::cout<<"no tienes una escopeta "<<std::endl;
        }
        else if (municion<2){
            std::cout<<"necesitas al menos 2 balas para disparar y tienes "<<municion<<std::endl;
        }
        else if(energia<6){
            std::cout<<"energia insuficiente"<<std::endl;
        }
        else{
            if (rango_escopeta(fila,col)) {
                if(simbolo=="z")danio=ataque*1.05;
                else danio=ataque*0.3;
                std::cout << "se disparo el arma" << std::endl;
                municion -= 2;
            }else{
                std::cout<<"fuera de rango"<<std::endl;
            }
        }
    }
    else if(opcion == 2){
        if(agua<=0){
            std::cout<<"no se cuenta con agua suficiente "<<std::endl;
        }
        else if(energia<6){
            std::cout<<"energia insuficiente"<<std::endl;
        }
        else{
            if(rango_agua(fila,col)) {
                if(simbolo=="z")danio=0;
                else danio=10;
                agua -= 1;
            }
            else{
                std::cout<<"fuera de rango"<<std::endl;
            }
        }
    }
    else if(opcion == 3){
        if (estacas<=0){
            std::cout<<"no tienes estacas"<<std::endl;
        }
        else if(energia<6){
            std::cout<<"energia insuficiente"<<std::endl;
        }
        else{
            if(rango_estaca(fila,col)) {
                if(simbolo=="z")danio=ataque*0.2;
                else danio=60;
            }else{
                std::cout<<"fuera de rango"<<std::endl;
            }
        }
    }
    else {
        std::cout<<"el cazador esta tan confundido que ataco con una rama"<<std::endl;
        danio = 0;
    }
    return danio;
}
void Cazavampiro::defender(){
    if(energia < 5)std::cout<<"energia insuficiente"<<std::endl;
    else{
        vida +=50;
    }
}
