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

	int pruebaId;

public:

	Menu(ABB<string, Objeto*>* diccionarioPersonajes, Tablero* tablero);

	void mostrarMenuPrincipal();

	void mostrarMenuSimulacion();

	void ingresarOpcionPrincipal();

	void ingresarOpcionSimulacion();

	void validarOpcionPrincipal(int & opcionPrincipal);

	void validarOpcionSimulacion(int & opcinonSimulacion);

	int obtenerOpcionMenuPrincipal();

	int obtenerOpcionSimulacion();

	void procesarOpcionPrincipal();

	void procesarOpcionSimulacion(Juego &nuevoJuego);

	void mostrarTablero();

	void buscarPersonajePorId();

	void eliminarDato();

	void mostrarOpcionesAAgregar();

	void agregarDato();

	void pedirCoordenadas(int &posicionX, int &posicionY);

	void validarOpcion(int &opcion, int minimo, int maximo);

	void crearSer(int posicionX, int posicionY, int opcion);

	void crearElemento(int posicionX, int posicionY, int opcion);

	virtual ~Menu();
};

#endif /* MENU_H_ */
