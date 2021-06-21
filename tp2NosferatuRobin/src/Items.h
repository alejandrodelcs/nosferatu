#ifndef ITEMS_H_
#define ITEMS_H_

#include <string>
#include "constantes.h"

class Items {

protected:

	std::string nombre;
	int posX;
	int posY;
	int cantidad;

public:

	//Items();

	Items(std::string nombre, int posicionX, int posicionY);

	Items(int posicionX, int posicionY);

	void asignar_nombre(std::string nombre);

	void asignar_coordX(int coordX);

	void asignar_coordY(int coordY);

	virtual void mostrar_contenido() = 0;

	int obtener_cantidad_elemento();

	std::string obtener_nombre();

	int obtener_coord_x();

	int obtener_coord_y();

	bool esta_en_NO();

	bool esta_en_NE();

	bool esta_en_SO();

	bool esta_en_SE();

	void informar_cuadrantes();

	virtual ~Items();
};

#endif /* ITEMS_H_ */
