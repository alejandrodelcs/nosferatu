#ifndef MENU_H_
#define MENU_H_

#include "constantes.h"

class Menu {

private:

	int opcionPrincipal;

	int opcionSimulacion;

public:

	Menu();

	void mostrarMenuPrincipal();

	void mostrarMenuSimulacion();

	void ingresarOpcionPrincipal();

	void ingresarOpcionSimulacion();

	void validarOpcionPrincipal(int & opcionPrincipal);

	void validarOpcionSimulacion(int & opcinonSimulacion);

	int obtenerOpcionMenuPrincipal();

	int obtenerOpcionSimulacion();

	void procesarOpcionPrincipal();

	void procesarOpcionSimulacion();

	virtual ~Menu();
};

#endif /* MENU_H_ */
