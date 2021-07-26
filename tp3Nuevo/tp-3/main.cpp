#include <iostream>
#include <cstdlib>
#include <ctime>
#include "interacciones.h"
#include "tablero.h"
#include "ABB.h"
#include "objeto.h"
//#include "Grafo.h"

#include "Menu.h"


int main() {


    srand(time(nullptr));

	Tablero* nuevoTablero = new Tablero();

	cout << "check1" << endl;

	ABB<string, Objeto*>* diccionarioPersonajes = new ABB<string, Objeto*>();   //Sacar puntero y pasar como parametro con ampersen (hacer estatico)

	cout << "check2" << endl;

	Interacciones* interacciones = new Interacciones(nuevoTablero, diccionarioPersonajes);

	cout << "checkpoint" << endl;


//    Grafo grafoHumanos;
//    grafoHumanos.crearMatrizAdyacencia(nuevoTablero);
//    grafoHumanos.cargarCaminosTablero(nuevoTablero, HUMANO);
//    Grafo grafoCazadores;
//    grafoCazadores.crearMatrizAdyacencia(nuevoTablero);
//    grafoCazadores.cargarCaminosTablero(nuevoTablero, CAZADOR);
//    Grafo grafoVampiros;
//    grafoVampiros.crearMatrizAdyacencia(nuevoTablero);
//    grafoVampiros.cargarCaminosTablero(nuevoTablero, VAMPIRO);
//    Grafo grafoZombies;
//    grafoZombies.crearMatrizAdyacencia(nuevoTablero);
//    grafoZombies.cargarCaminosTablero(nuevoTablero, ZOMBIE);
//
//
//    Lista<Coordenadas*>* movimientos = new Lista<Coordenadas*>();
//    int energiaNecesaria = 0;
//    grafoHumanos.calcularMatricesFloyd();
//    grafoHumanos.caminoMinimo(nuevoTablero->obtenerCasillero(0,0), nuevoTablero->obtenerCasillero(4,4), nuevoTablero, movimientos, energiaNecesaria);
//    cout << energiaNecesaria << endl;


    //Lista<Ser*> personajesBuenos;
    //Lista<Ser*> personajesMalos;
    //Juego nuevoJuego(PersonajesBuenos, PersonajesMalos, Tablero)
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


    //FUNCION PARA BORRAR LOS OBJETOS DE TIPO COORDENADAS QUE ESTAN DENTRO DE LOS NODOS DE LA LISTA
//    for (int i = 1; i <= movimientos->obtenerLargo(); i++){
//    	Coordenadas* coord = movimientos->consulta(i);
//    	//cout << "CoordX: " << coord->obtenerCoordenadaX() << "CoordY: " << coord->obtenerCoordenadaY() << endl;
//    	delete coord;
//    }
//
//    delete movimientos;

	delete nuevoTablero;
	delete diccionarioPersonajes;
	delete interacciones;
	delete menu;


return 0;
}
