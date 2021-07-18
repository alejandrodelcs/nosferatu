#include <iostream>
#include <cstdlib>
#include <ctime>
#include "interacciones.h"
#include "tablero.h"
#include "ABB.h"
#include "objeto.h"


int main() {

    srand(time(nullptr));

	Tablero* nuevoTablero = new Tablero();

	ABB<string, Objeto*>* diccionarioPersonajes = new ABB<string, Objeto*>();

	Interacciones* interacciones = new Interacciones(nuevoTablero, diccionarioPersonajes);

	nuevoTablero->mostrarTablero();
	std::cout << endl;
	nuevoTablero->mostrarTableroObjetos();

	diccionarioPersonajes->buscar("321")->mostrar();

	delete nuevoTablero;
	delete diccionarioPersonajes;
	delete interacciones;
}
