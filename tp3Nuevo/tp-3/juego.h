#include "lista.h"
#include "ser.h"
#include "tablero.h"

const std::string LIMITE_ID_PERSONAJES_BUENOS = "100";
const int OPCION_MINIMA = 1, OPCION_MAXIMA = 4;


#ifndef TP_3_JUEGO_H_
#define TP_3_JUEGO_H_

class Juego{
private:
	Lista<Ser*>* personajesBuenos = new Lista<Ser*>;
	Lista<Ser*>* personajesMalos = new Lista<Ser*>;
public:
	//Juego();

	void crearEquipos(Tablero* tablero);

	void mostrarCantidadPersonajes();

	~Juego();

};



#endif /* TP_3_JUEGO_H_ */
