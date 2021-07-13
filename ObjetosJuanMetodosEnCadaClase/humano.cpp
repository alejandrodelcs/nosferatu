#include "humano.h"

Humano::Humano(int fila, int columna, std::string id, int vida, int ataque, int armadura, int energia):Ser(fila,columna,id,vida,ataque,armadura,energia){
    this->simbolo = "h";

};

void Humano::mostrar() {
    std::cout << "humano" << std::endl;
}


int Humano::obtenerColumna(){
	Ser::obtenerColumna();
}

int Humano::obtenerFila(){
	Ser::obtenerFila();
}

std::string Humano::obtenerId(){
	Ser::obtenerId();
}

std::string Humano::obtenerSimbolo(){
	Ser::obtenerSimbolo();
}

void Humano::atacar(){
	Ser::atacar();
}

void Humano::defender(){
	Ser::atacar();
}

