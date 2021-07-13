//
// Created by alejandro on 08/07/2021.
//

#include "interacciones.h"





Tablero* Interacciones::cargarMatriz() {
    std::ifstream archivo;
    archivo.open(PATH, std::ios::in);

    std::string lineaArchivo;
    std::string nombreItem;
    std::string coordenadaXStr, coordenadaYStr;
    int ancho, largo;
    int posX, posY;
    int cantidad;
    Objeto* objeto;
    Tablero *tablero = nullptr;

    if(archivo.is_open()){
        std::cout << "el archivo se abrio de manera exitosa" << std::endl;
        getline(archivo, coordenadaXStr,' ');
        getline(archivo, coordenadaYStr);
        ancho = stoi(coordenadaXStr);
        largo = stoi(coordenadaYStr);
        tablero =  new Tablero(ancho,largo);

        while(getline(archivo,lineaArchivo)){
            Estado estado(lineaArchivo);
            std::cout<<estado.devolverId()<<std::endl; //PRUEBA
        }
    }else{
        std::cerr<<"ERROR!...el Archivo"<<PATH<<"No se abrio"<<std::endl;
    }
    return tablero;
}


