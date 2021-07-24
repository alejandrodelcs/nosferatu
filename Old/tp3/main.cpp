#include <iostream>
#include <cstdlib>
#include <ctime>
#include "interacciones.h"
#include "tablero.h"
#include "ABB.h"
#include "objeto.h"

#include "Menu.h"


int main() {


    srand(time(nullptr));

	Tablero* nuevoTablero = new Tablero();

	ABB<string, Objeto*>* diccionarioPersonajes= new ABB<string, Objeto*>();   //Sacar puntero y pasar como parametro con ampersen (hacer estatico)

	Interacciones* interacciones = new Interacciones(nuevoTablero, diccionarioPersonajes);

//	std::cout << "busca" << std::endl;
//	diccionarioPersonajes->buscar("456");
//	std::cout << "termina busqueda" << std::endl;

	//nuevoTablero->mostrarTablero();
//	std::cout << endl;
//	nuevoTablero->mostrarTableroObjetos();
//	nuevoTablero->eliminarDato(3,4);
//	std::cout << endl;
//	nuevoTablero->mostrarTableroObjetos();


	Menu* menu = new Menu(diccionarioPersonajes, nuevoTablero);  //Sacar puntero y hacer estatico
	int opcionPrincipal = menu->obtenerOpcionMenuPrincipal();

	while(opcionPrincipal != SALIR_MENU_PRINCIPAL){          //Pasar opcion principal como parametro.
		menu->procesarOpcionPrincipal();
		cout << endl;
		menu->ingresarOpcionPrincipal();
		opcionPrincipal = menu->obtenerOpcionMenuPrincipal();
	}
	cout << "Vamo Messi!" << endl;

	delete nuevoTablero;
	delete diccionarioPersonajes;
	delete interacciones;
	delete menu;


return 0;
}
