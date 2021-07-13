#include "zombi.h"

Zombi::Zombi(int fila, int columna, std::string id, int vida, int ataque,int armadura,int energia):Monstruo(fila,columna,id,vida,ataque,armadura, energia) {
    this->simbolo = "z";
}

void Zombi::mostrar() {
    std::cout << "el zombi" << std::endl;
}

int Zombi::obtenerColumna(){
	Monstruo::obtenerColumna();
}

int Zombi::obtenerFila(){
	Monstruo::obtenerFila();
}

std::string Zombi::obtenerId(){
	Monstruo::obtenerId();
}

std::string Zombi::obtenerSimbolo(){
	Monstruo::obtenerSimbolo();
}

void Zombi::atacar(){
	Monstruo::atacar();
}

void Zombi::defender(){
	Monstruo::atacar();
}