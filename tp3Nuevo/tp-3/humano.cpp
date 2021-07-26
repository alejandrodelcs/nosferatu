#include "humano.h"

Humano::Humano(int fila, int columna, std::string id){
    this->fila = fila;
    this->columna = columna;
    this->simbolo = "h";
    this->id = id;
    this->vida = asignarVida();
    this->ataque = asignarAtaque();
    this-> escopeta=false;
    this-> municion=true;
}

std::string Humano::obtenerSimbolo() {
    return simbolo;
}

void Humano::mostrar() {
    std::cout << "Humano" << std::endl;
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
    return se_obtuvo_el_objeto;
}
void Humano::atacar(){
	std::cout << "ataco" << std::endl;
}

void Humano::defender(){
	std::cout << "defiendo" << std::endl;
}
bool Humano::rango_escopeta(int fila, int col) {
    return(fila<=this->fila+2 && col<=this->columna+2);
}

bool Humano::esta_en_rango(int fila, int col) {
    if(!escopeta){
        std::cout<<"no tienes una escopeta "<<std::endl;
        return false;
    }
    else if (municion<2){
        std::cout<<"necesitas almenos 2 balas para disparar y tienes "<<municion<<std::endl;
        return false;
    }
    else{
        if (rango_escopeta(fila,col)) {
            std::cout << "se disparo el arma" << std::endl;
            municion -= 2;
            return true;
        }else{
            std::cout<<"fuera de rango"<<std::endl;
            return false;
        }
    }
}
