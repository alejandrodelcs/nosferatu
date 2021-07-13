#include "monstruo.h"

Monstruo::Monstruo(int fila, int columna, std::string id, int vida, int ataque, int armadura, int energia):Ser(fila,columna,id,vida,ataque,armadura,energia){

}

void Monstruo::mostrar() {
    Ser::mostrar();
}

int Monstruo::obtenerColumna(){
	Ser::obtenerColumna();
}

int Monstruo::obtenerFila(){
	Ser::obtenerFila();
}

std::string Monstruo::obtenerId(){
	Ser::obtenerId();
}

std::string Monstruo::obtenerSimbolo(){
	Ser::obtenerSimbolo();
}

void Monstruo::atacar(){
	Ser::atacar();
}

void Monstruo::defender(){
	Ser::atacar();
}
