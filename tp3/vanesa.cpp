#include "vanesa.h"

Vanesa::Vanesa(int fila, int columna, std::string id) : Cazavampiro(fila, columna, id){
    this->fila = fila;
    this->columna = columna;
    this->simbolo = "W";
    this->id = id;
    this->vida = asignarVida();
    this->ataque = asignarAtaque();
    this-> escopeta = false;
    this-> municion = 0;
    this-> estacas = 0;
    this-> agua = 0;
}

std::string Vanesa::obtenerSimbolo() {
    return simbolo;
}


void Vanesa::mostrar() {
    std::cout << "Vanesa Helsing" << std::endl;
}
bool Vanesa::tomar_objeto(std::string objeto,int cant) {
    bool se_obtuvo_el_objeto=false;
    if(objeto=="E" && !escopeta){
        escopeta=true;
        se_obtuvo_el_objeto=true;
    }
    else if (objeto=="A"){
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
    return se_obtuvo_el_objeto;
}
bool Vanesa::rango_agua(int fila,int col) {
    return(fila<=this->fila+1 && col<=this->columna+1);
}
bool Vanesa::rango_escopeta(int fila, int col) {
    return(fila<=this->fila+2 && col<=this->columna+2);
}
bool Vanesa::rango_estaca(int fila, int col) {
    return((fila == this->fila-1 && col == this->columna) ||
           (fila == this->fila && col == this->columna-1) ||
           (fila == this->fila+1 && col == this->columna) ||
           (fila == this->fila && col == this->columna+1));
}
bool Vanesa::esta_en_rango(int fila, int col) {
    int opcion;
    std::cout<<"seleccione un arma"<<std::endl;
    std::cout<<"(1) escopeta"<<std::endl;
    std::cout<<"(2) agua"<<std::endl;
    std::cout<<"(3) estaca"<<std::endl;
    std::cin>>opcion;
    if (opcion == 1){
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
    else if(opcion == 2){
        if(agua<=0){
            std::cout<<"no se cuenta con agua suficiente "<<std::endl;
            return false;
        }else{
            if(rango_agua(fila,col)) {
                agua -= 1;
                return true;
            }else{
                std::cout<<"fuera de rango"<<std::endl;
                return false;
            }
        }
    }
    else if(opcion == 3){
        if (estacas<=0){
            std::cout<<"no tienes estacas"<<std::endl;
            return false;
        }
        else{
            if(rango_estaca(fila,col)) {
                estacas -= 1;
                return true;
            }else{
                std::cout<<"fuera de rango"<<std::endl;
                return false;
            }
        }
    }
    else esta_en_rango(fila,col);
}