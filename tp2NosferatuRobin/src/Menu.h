#ifndef MENU_H_
#define MENU_H_

#include "MatrizItems.h"
#include "Contadores.h"

class Menu {

private:

	int opcion;

public:

	Menu();

	void mostrar_menu();

	void ingresar_opcion();

	void validar_opcion(int & opcion);

	int obtener_opcion_menu();

	void procesar_opcion(MatrizItems* & matriz);

	virtual ~Menu();
};

#endif /* MENU_H_ */
