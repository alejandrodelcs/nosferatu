#ifndef MENU_H_
#define MENU_H_

#include "constantes.h"
#include "ABB.h"
#include "tablero.h"
#include "identificador.h"
#include "juego.h"

class Menu {

private:

	int opcionPrincipal;

	int opcionSimulacion;

	ABB<string, Objeto*>* diccionarioPersonajes;

	Tablero* tablero;

	Identificador iden;

public:

	//PRE:
	//POS: Crea un menú para el juego.
	Menu(ABB<string, Objeto*>* diccionarioPersonajes, Tablero* tablero);

	//PRE:
	//POS: Muestra las opciones del menú principal.
	void mostrarMenuPrincipal();

	//PRE:
	//POS: Muestra las opciones del menú de la simulación (o del juego).
	void mostrarMenuSimulacion();

	//PRE:
	//POS: Le pide al usuario que ingrese una opción para el menú principal.
	void ingresarOpcionPrincipal();

	//PRE:
	//POS: Le pide al usuario que ingrese una opción para el menú del juego.
	void ingresarOpcionSimulacion();

	//PRE:
	//POS: Valida que la opción ingresada por el usuario en el menú principal sea correcta y si no lo es
	//     le pide una nueva hasta que lo sea.
	void validarOpcionPrincipal(int & opcionPrincipal);

	//PRE:
	//POS: Valida que la opcion ingresada por el usuario en el menú del juego sea correcta y si no lo es
	//     le pide una nueva hasta que lo sea.
	void validarOpcionSimulacion(int & opcinonSimulacion);

	//PRE:
	//POS: Devuelve la opción ingresada en el menú principal.
	int obtenerOpcionMenuPrincipal();

	//PRE:
	//POS: Devuelve la opción ingresada en el menú del juego.
	int obtenerOpcionSimulacion();

	//PRE:
	//POS: Procesa la opción ingresada por el usuario y en base a la misma realiza diferentes tareas.
	void procesarOpcionPrincipal();

	//PRE:
	//POS: Procesa la opción ingresada por el usuario y en base a la misma realiza diferentes tareas.
	void procesarOpcionSimulacion(Juego &nuevoJuego);

	//PRE:
	//POS: Muestra el tablero en base a los personajes y objetos que contiene.
	void mostrarTablero();

	//PRE:
	//POS: Busca un personaje en el diccionario y muestra sus atributos.
	void buscarPersonajePorId();

	//PRE:
	//POS: Elimina un personaje u objeto en base a una posición en el tablero ingresada por el usuario.
	//     Borra el personaje accediendo a él mediante el tablero y luego elimina el nodo que lo contenía
	//	   en el diccionario.
	void eliminarDato();

	//PRE:
	//POS: Muestra las opciones de objetos que puede agregar al juego.
	void mostrarOpcionesAAgregar();

	//PRE:
	//POS: Decide, dependiendo de la opción ingresada por el usuario si se crea un objeto de tipo Ser o
	//     de tipo Elemento y llama a las respectivas funciones para que lo agreguen al juego.
	void agregarDato();


	//PRE:
	//POS: Le pide coordenadas al usuario y las corrige a su posición lógica.
	void pedirCoordenadas(int &posicionX, int &posicionY);

	//PRE:
	//POS: Valida que la opcion ingresada (pasada por parámetro) se encuentre entre el mínimo y el máximo.
	void validarOpcion(int &opcion, int minimo, int maximo);

	//PRE:
	//POS: Crea un personaje de tipo Ser y lo agrega tanto al tablero como al diccionario.
	void crearSer(int posicionX, int posicionY, int opcion);

	//PRE:
	//POS: Crea un objeto de tipo Elemento y lo agrega tanto al tablero como al diccionario.
	void crearElemento(int posicionX, int posicionY, int opcion);

	virtual ~Menu();
};

#endif /* MENU_H_ */
