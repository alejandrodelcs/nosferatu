#include <string>
#include "ser.h"
#include "elemento.h"

#ifndef CASILLERO_H_
#define CASILLERO_H_

class Casillero{
private:
	std::string terreno;
	bool hayPersonajeEnCasillero;
	bool hayElementoEnCasillero;
	Ser* personaje;
	Elemento* elemento;
public:

	//Crea un casillero vacío
	Casillero();

	//PRE:
	//POS: Asigna el tipo de terreno que tiene el casillero
	void asignarTerreno(std::string terreno);

	//PRE:
	//POS: Devuelve el tipo de terreno que tiene el casillero
	std::string obtenerTerreno();

	//PRE:
	//POS: Devuelve true si hay un personaje en el casillero, false en caso contrario
	bool hayPersonaje();

	//PRE:
	//POS: Devuelve true si hay un elemento en el casillero, false en caso contrario
	bool hayElemento();

	//PRE: El casillero está vacío
	//POS: Asigna un personaje al casillero y marca que está ocupado con un personaje
	void asignarPersonaje(Ser* personajeNuevo);

	//PRE: El casillero está ocupado por un personaje
	//POS: Devuelve el personaje que se encuentra en el casillero
	Ser* obtenerPersonaje();

	//PRE: El casillero está ocupado por un personaje
	//POS: Deja el casillero sin personaje haciendo que el puntero apunte a nullptr y que hayPersonajeEnCasillero sea falso.
	//IMPORTANTE: este método no elimina el personaje
	void quitarPersonaje();

	//PRE:
	//POS: Asigna un elemento al casillero y lo marca como ocupado por un elemento
	void asignarElemento(Elemento* elementoNuevo);

	//PRE: En el casillero hay un elemento
	//POS: Devuelve el elemento
	Elemento* obtenerElemento();

	//PRE: En el casillero hay un elemento
	//POS: Deja el casillero sin elemento haciendo que el puntero apunte a nullptr y que hayElementoEnCasillero sea falso.
	void quitarElemento();

};



#endif /* CASILLERO_H_ */
