#include "estado.h"

Estado::Estado() {
    this->cantidad = 0;
    this->lineaArchivo = "";
    this->identificador = "";
    this->posicionX = 0;
    this->posicionY = 0;
}

void Estado::nombreObjeto() {
    this->nombre = lineaArchivo.substr(0, int(this->lineaArchivo.find(' ')));
}

void Estado::coordenadaObjeto() {
    this->coordenada = lineaArchivo.substr(int(this->lineaArchivo.find(' ')) + 1);
}


void Estado::leerLineaArchivo(std::string linea) {
    this->lineaArchivo = linea;
    nombreObjeto();
    coordenadaObjeto();

}

void Estado::validarNombreObjeto(){
    if (int(this->coordenada.find("CV")) != -1)
        this->nombre="CV";
}

std::string Estado::devolverNombreObjeto() {
    validarNombreObjeto();
    return this->nombre;
}


void Estado::validarCantidadObjeto() {
    if ((coordenada[0] != '(') && (int(this->coordenada.find("CV")) == -1))
        this->cantidad = stoi(this->coordenada.substr(0, this->coordenada.find(' ')));
    else
        this->cantidad = 0; //si el objeto no tene cantidad devuelve 0
}

int Estado::devolverCantidad(){

    validarCantidadObjeto();
    return this->cantidad;
}

void Estado::validarPosicionX(){
    if ((int(this->coordenada.find("CV")) != -1 || int(NUMEROS.find(this->coordenada[0])) != -1)
    && (int(NUMEROS.find(this->nombre[0])) == -1)){
        this->posicionX = stoi(this->coordenada.substr(int(coordenada.find('(')) + 1,
                                                       int(coordenada.find(',')) - int(coordenada.find('(')) - 1));
    }else{
        this->posicionX = stoi(coordenada.substr(1, int(coordenada.find(',')) - 1));
    }
}

int Estado::devolverPosx() {
    validarPosicionX();
    return this->posicionX-1;
}

void Estado::validarPosicionY() {
    this->posicionY = stoi(coordenada.substr(int(coordenada.find(',')) + 2, int(coordenada.find(')')) - 2));
}

int Estado::devolverPosy() {
    validarPosicionY();
    return this->posicionY-1;
}


void Estado::validarIdentificador() {
    if (int(lineaArchivo.find(')')) != -1){
        this->identificador = lineaArchivo.substr(lineaArchivo.find(')')+2);
    }
}

std::string Estado::devolverId() {
    validarIdentificador();
   return this->identificador;
}




#include "estado.h"
