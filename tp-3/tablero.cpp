//
// Created by alejandro on 06/07/2021.
//

#include "tablero.h"

Tablero::Tablero() {
    this->abscisa = 0;
    this->ordenada = 0;
    pObjeto = nullptr;
}


Tablero::Tablero(int fila, int columna) {
    this->abscisa = fila;
    this->ordenada = columna;
    pObjeto = new Objeto **[fila];
    for (int i = 0; i < fila; i++) {
        pObjeto[i] = new Objeto *[columna];
        for (int j = 0; j < columna; j++) {
            pObjeto[i][j] = nullptr;
        }
    }
}


void Tablero::imprimirTablero()
{
    for(int i= 0; i<this->abscisa; i++) {
        for (int j = 0; j < this->ordenada; j++) {
            if (this->pObjeto[i][j] == nullptr) {
                std::cout << "* ";
            } else {
                std::cout << pObjeto[i][j]->simbolo <<" ";
            }
        }
        std::cout << std::endl;
    }
}



Tablero::~Tablero() {
    for(int i = 0;i < this->abscisa;i++) {
        for (int j = 0; j < this->ordenada; j++) {
            if (pObjeto[i][j] != nullptr) {
                delete pObjeto[i][j];
                pObjeto[i][j] = nullptr;
            }
        }
    }
    for(int i = 0;i < this->abscisa;i++)
    {
        delete[] pObjeto[i];
        pObjeto[i] = nullptr;
    }
    delete[] pObjeto;
    pObjeto = nullptr;
}


