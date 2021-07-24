#include <iostream>
#include <string>
#include "casillero.h"
#include <fstream>

using namespace std;


#ifndef TABLERO_H_
#define TABLERO_H_

class Tablero{
private:
	Casillero*** tablero;
	int cantidadFilas;
	int cantidadColumnas;
	int noroeste[4];           //Los limites están formados de la forma
	int noreste[4];            //[inferiorX, superiorX, inferiorY, superiorY]
	int suroeste[4];
	int sureste[4];

	int cantidadHumanos = 0;
	int cantidadVampiros = 0;
	int cantidadZombies = 0;
	int cantidadAguaBendita = 0;
	int cantidadCruces = 0;
	int cantidadEstacas = 0;
	int cantidadEscopetas = 0;
	int cantidadBalas = 0;

	//PRE:
	//POS: Divide al tablero en cuatro cuadrantes (NO,NE,SO,SE)
	void establecerCuadrantes();

	//PRE: Existe un archivo bien formado con el tamaño del tablero y los terrenos en cada posición.
	//POS: Carga los terrenos en cada casillero.
	void cargarTablero();

	//PRE:
	//POS: Crea un tablero del tamaño pasado por parámetros (el tablero es una matriz
	//     de punteros a casilleros que apuntan a nullptr).
	void crearTablero(int cantidadFilas, int cantidadColumnas);

	//PRE:
	//POS: Hace que todos los punteros a casilleros apunten a un casillero.
	void inicializarTablero();


public:

	Tablero();

	//PRE:
	//POS: Crea un tablero con las dimensiones pasadas por parámetro.
	Tablero(int cantidadFilas, int cantidadColumnas);


	//PRE:
	//POS: Muestra el tablero con sus terrenos.
	void mostrarTablero();

	//PRE:
	//POS: Muestra el tablero con sus objetos.
	void mostrarTableroObjetos();

	//PRE:
	//POS: Verifica que la posición elegida se encuentra dentro de
	//     los límites del tablero.
	bool esPosicionValida(int posicionX, int posicionY);

	//PRE: Las posiciones son válidas y existe un objeto en las mismas.
	//POS: Devuelve el objeto pedido por las posiciones.
	Casillero* obtenerCasillero(int posicionX, int posicionY);

	//PRE: Las posiciones son válidas y no hay otro personaje en el casillero.
	//POS: Agrega un personaje al casillero.
	void agregarDato(int posicionX, int posicionY, Ser* nuevoPersonaje);

	//PRE: Las posiciones son válidas y no hay otro elemento en el casillero.
	//POS: Agrega un elemento al casillero.
	void agregarDato(int posicionX, int posicionY, Elemento* nuevoElemento);

	//PRE: Existe un personaje u objeto en la posición indicada.
	//POS: Elimina el personaje u objeto que se encuentra en esa posición.
	void eliminarDato(int posicionX, int posicionY);

	//PRE:
	//POS: Devuelve los límites que definen al cuadrante Noroeste, esto es un vector
	//     de tamaño 4 definido por los límites [inferiorX, superiorX, inferiorY, superiorY]
	int* getNoroeste();

	//PRE:
	//POS: Devuelve los límites que definen al cuadrante Noreste, esto es un vector
	//     de tamaño 4 definido por los límites [inferiorX, superiorX, inferiorY, superiorY]
	int* getNoreste();

	//PRE:
	//POS: Devuelve los límites que definen al cuadrante Suroeste, esto es un vector
	//     de tamaño 4 definido por los límites [inferiorX, superiorX, inferiorY, superiorY]
	int* getSuroeste();

	//PRE:
	//POS: Devuelve los límites que definen al cuadrante Sureste, esto es un vector
	//     de tamaño 4 definido por los límites [inferiorX, superiorX, inferiorY, superiorY]
	int* getSureste();

	//PRE:
	//POS: Elimina el tablero y los objetos presentes en el mismo, liberando la memoria utilizada.
	~Tablero();




};


#endif /* TABLERO_H_ */
