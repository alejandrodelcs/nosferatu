#include <iostream>
#include <cstdlib>
#include <ctime>
#include "interacciones.h"
#include "tablero.h"
#include "ABB.h"
#include "objeto.h"

#include "Menu.h"


int main() {

	/*
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
*/


	Menu menu;
	int opcionPrincipal = menu.obtenerOpcionMenuPrincipal();

	while(opcionPrincipal != SALIR_MENU_PRINCIPAL){
		menu.procesarOpcionPrincipal();
		cout << endl;
		menu.ingresarOpcionPrincipal();
		opcionPrincipal = menu.obtenerOpcionMenuPrincipal();
	}
	cout << "Vamo Messi!" << endl;


return 0;
}
