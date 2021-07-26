#include "ser.h"
#include "tablero.h"
#include "Grafo.h"

const std::string LIMITE_ID_PERSONAJES_BUENOS = "100";
const int OPCION_MINIMA = 1, OPCION_MAXIMA = 4;


#ifndef TP_3_JUEGO_H_
#define TP_3_JUEGO_H_

class Juego{
private:
	Lista<Ser*>* personajesBuenos = new Lista<Ser*>;
	Lista<Ser*>* personajesMalos = new Lista<Ser*>;

	Lista<Ser*>* jugador1;
	Lista<Ser*>* jugador2;

	Grafo grafoHumanos;
	Grafo grafoCazadores;
	Grafo grafoVampiros;
	Grafo grafoZombies;

	void validarOpcion(int &opcion, int opcionMinima, int opcionMaxima);

public:
	//Juego();

	void crearEquipos(Tablero* tablero);

	void mostrarCantidadPersonajes();

	void elegirBando();

	void comenzarJuego(Tablero* tablero);

	int decidirPrimerTurno();

	void jugar(Lista<Ser*>* primerJugador, Lista <Ser*>* segundoJugador, bool &continuar, Tablero* tablero);

	void mostrarMenuPersonaje(Ser* personajeAJugar);

	void preguntarSiDeseaContinuar(bool &continuar);

	int pedirOpcion();

	void elegirOpcion(Ser* personaje, Tablero* tablero);

	void pasarTurno();

	void moverse(Ser* personaje, Tablero* tablero);

	void obtenerNuevaPosicion(int &posicionX, int &posicionY);

	void cargarGrafos(Tablero* tablero);

	void mostrarGrafos();

	bool esCaminoValido(Lista<Coordenadas*>* movimientos, Tablero* tablero);

	~Juego();

};



#endif /* TP_3_JUEGO_H_ */
