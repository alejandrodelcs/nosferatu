//
// Created by alejandro on 08/07/2021.
//

#include "interacciones.h"
#include "tablero.h"
#include "ABB.h"

Interacciones::Interacciones(Tablero* tablero, ABB<std::string, Objeto*>* diccionarioPersonajes){
	cargarMatriz(tablero, diccionarioPersonajes);
}


void Interacciones::cargarMatriz(Tablero* tablero, ABB<std::string, Objeto*>* diccionarioPersonajes) {
    std::ifstream archivo;
    archivo.open(PATH, std::ios::in);

    std::string lineaArchivo;
    std::string nombreItem;
    std::string coordenadaXStr, coordenadaYStr;
    //int ancho, largo;
    //ABB<std::string, Objeto *> *diccionarioPersonajes = new ABB<std::string, Objeto *>;
    if (archivo.is_open()) {
        std::cout << "el archivo se abrio de manera exitosa" << std::endl;
//        getline(archivo, coordenadaXStr, ' ');
//        getline(archivo, coordenadaYStr);
//        ancho = stoi(coordenadaXStr);
//        largo = stoi(coordenadaYStr);
        //this->tablero = new Tablero(ancho, largo);

        while (getline(archivo, lineaArchivo)) {
            Estado estado(lineaArchivo);
            validarSer(estado.devolverId());

            decidirObjeto(estado.devolverId(), estado.devolverPosx(), estado.devolverPosy(), estado.devolverNombre(),
                          estado.devolverCantidad(), diccionarioPersonajes, tablero);
        }
    } else {
        std::cerr << "ERROR!...el Archivo" << PATH << "No se abrio" << std::endl;
        exit(1);
    }
    //diccionarioPersonajes->imprimirArbol();
    diccionarioPersonajes->imprimirPadre("052");
    diccionarioPersonajes->imprimirIzquierdo("321");
    diccionarioPersonajes->imprimirDerecho("052");
}



bool Interacciones::validarMonstruo(const std::string& id) {
    return id >= "100" && id <= "299";
}

bool Interacciones::validarElemento(const std::string& id) {
    return id >= "300" && id <= "999";
}

bool Interacciones::validarSer(const std::string& id) {
    return id >= "000" && id <= "099";
}


void Interacciones::decidirObjeto(const std::string& id, int fila, int columna, const std::string& nombre, int cantidad,
                                  ABB<std::string, Objeto *> *diccionarioPersonajes, Tablero* tablero) {

    if (validarElemento(id)) {
        crearElemento(id, fila, columna, nombre, cantidad, diccionarioPersonajes, tablero);
    }else if (validarMonstruo(id)){
        crearMounstruo(id, fila, columna, nombre, diccionarioPersonajes, tablero);
    }else{
        crearSer(id, fila, columna, nombre, diccionarioPersonajes, tablero);
    }

}


void
Interacciones::crearElemento(const std::string& id, int fila, int columna, const std::string& nombre, int cantidad,
                             ABB<std::string, Objeto *> *diccionarioPersonajes, Tablero* tablero) {
    Elemento *aux;
    if (nombre == "agua") {
        aux = new Agua(fila, columna, id, cantidad);
    } else if (nombre == "bala") {
        aux = new Balas(fila, columna, id, cantidad);
    } else if (nombre == "cruz") {
        aux = new Cruz(fila, columna, id, cantidad);
    } else if (nombre == "escopeta") {
        aux = new Escopeta(fila, columna, id, cantidad);
    } else {
        aux = new Estaca(fila, columna, id, cantidad);
    }

    tablero->agregarDato(fila, columna, aux);
    diccionarioPersonajes->agregarDato(id, aux);


}

void Interacciones::crearMounstruo(const std::string& id, int fila, int columna, const std::string& nombre,
                                   ABB<std::string, Objeto *> *diccionarioPersonajes, Tablero* tablero) {
    Monstruo* aux;
    if (nombre == "Nosferatu"){
        aux = new Nosferatu(fila,columna,id);
    } else if (nombre == "Vampirella"){
        aux = new Vampirella(fila,columna,id);
    } else if (nombre == "vampiro"){
        aux = new Vampiro(fila,columna,id);
    }else {
        aux = new Zombi(fila,columna,id);
    }
    tablero->agregarDato(fila, columna, aux);
    diccionarioPersonajes->agregarDato(id,aux);


}

void Interacciones::crearSer(const std::string& id, int fila, int columna, const std::string& nombre,
                             ABB<std::string, Objeto *> *diccionarioPersonajes, Tablero* tablero) {
    Ser* aux;

    if(nombre == "humano"){
        aux = new Humano(fila,columna,id);
    }else if (nombre == "CV"){
        aux = new Cazavampiro(fila,columna,id);
    }else{
        aux = new Vanesa(fila,columna,id);
    }
    tablero->agregarDato(fila, columna, aux);
    diccionarioPersonajes->agregarDato(id,aux);


}

//Interacciones::~Interacciones() {
//    delete tablero;
//}





