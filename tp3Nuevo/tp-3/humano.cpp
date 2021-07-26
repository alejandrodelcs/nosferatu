#include "humano.h"

Humano::Humano(int fila, int columna, std::string id){
    this->fila = fila;
    this->columna = columna;
    this->simbolo = "h";
    this->id = id;
    this->vida = asignarVida();
    this->ataque = asignarAtaque();
    this->energia=asignarEnergia();
    this->armadura=asignarArmdura();
    this-> escopeta=false;
    this-> municion=0;
    this-> agua=0;
}

std::string Humano::obtenerSimbolo() {
    return simbolo;
}

void Humano::mostrar() {
    std::cout << "Humano "<<fila <<" "<<columna<<std::endl;
    std::cout << " vida "<<vida<<std::endl;
    std::cout<<" energia = "<<agua<<std::endl;
    std::cout << " armadura "<<vida<<std::endl;
    std::cout<<" agua = "<<agua<<std::endl;
    std::cout<<" escopeta= "<<escopeta<<std::endl;
    std::cout<<" balas "<<municion <<std::endl;
}
bool Humano::tomar_objeto(std::string objeto,int cant) {
    bool se_obtuvo_el_objeto=false;
    if(objeto=="E" && !escopeta){
        escopeta=true;
        se_obtuvo_el_objeto=true;
    }
    else if(objeto == "b"){
        se_obtuvo_el_objeto=true;
        municion+=cant;
    }
    else if(objeto == "a"){
        agua +=1;
        se_obtuvo_el_objeto=true;
    }
    return se_obtuvo_el_objeto;
}

void Humano::defender(){
	int opcion=0;
    std::cout<<"desea gastar 1 vial de agua para regenerar la energia? (S) "<<std::endl;
	std::cin>>opcion;
	if(opcion == 1){
	    if(agua>0) {
            energia = 20;
            agua -=1;
            std::cout << "se regenero la energia" << std::endl;
        }else std::cout<< "no hay agua"<< std::endl;
	}
	else std::cout<< "opcion no valida"<<std::endl;
}
bool Humano::rango_escopeta(int fila, int col) {
    return(fila<=this->fila+2 && col<=this->columna+2);
}

bool Humano::esta_en_rango(int fila, int col) {
    bool se_puede_atacar=false;
    if(!escopeta){
        std::cout<<"no tienes una escopeta "<<std::endl;
        se_puede_atacar= false;
    }
    else if (municion<2){
        std::cout<<"necesitas almenos 2 balas para disparar y tienes "<<municion<<std::endl;
        se_puede_atacar= false;
    }
    else if (energia<5){
        std::cout<<"no tienes energia"<<std::endl;
        se_puede_atacar=false;
    }
    else{
        if (rango_escopeta(fila,col)) {
            std::cout << "se disparo el arma" << std::endl;
            municion -= 2;
            se_puede_atacar= true;
        }else{
            std::cout<<"fuera de rango"<<std::endl;
            se_puede_atacar= false;
        }
    }
    return se_puede_atacar;
}
void Humano::recuperarEnergia() {
    energia +=5;
}

int Humano::atacar(int fila, int col,std::string simbolo) {
    int danio=0;
    if(esta_en_rango(fila,col)){
        if(simbolo=="z"){
            energia -=5;
            danio=this->ataque;
        }
        else{
            energia -=5;
            danio=this->ataque*0.2;
        }
    }
    return danio;
}

void Humano::recibir_ataque(int ataque){
    if(armadura==1)ataque=ataque*0.9;
    else if(armadura==2)ataque=ataque*0.8;
    else if(armadura>2)ataque=ataque*0.2;
    vida -=ataque;
}