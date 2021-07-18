#include <iostream>
#include <string>
#include "casillero.h"
#include <fstream>

using namespace std;

const string HUMANO = "humano", HUMANO_CV = "CV", VANESA = "Vanesa", ZOMBIE = "zombi", VAMPIRO = "vampiro",
			 VAMPIRELLA = "Vampirella", NOSFERATU = "Nosferatu", CRUZ = "cruz", AGUA_BENDITA = "agua",
			 ESTACA = "estaca", ESCOPETA = "escopeta", BALAS = "bala";



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


public:

	Tablero();

	//PRE:
	//POS: Crea un tablero con las dimensiones pasadas por parámetro.
	Tablero(int cantidadFilas, int cantidadColumnas);

	void inicializarTablero();

	//PRE:
	//POS: Muestra el tablero.
	void mostrarTablero();

	//PRE: La posición se encuentra dentro de los límites del tablero.
	//POS: Corrige las coordenadas y verifica que la posción elegida está vacía.
	bool esPosicionVacia(int posicionX, int posicionY);

	//PRE:
	//POS: Corrige las coordenadas y verifica que la posición elegida se encuentra dentro de
	//     los límites del tablero.
	bool esPosicionValida(int posicionX, int posicionY);

	//PRE: Las posiciones son válidas y existe un objeto en las mismas.
	//POS: Corrige las coordenadas y devuelve el objeto pedido por las posiciones.
	Casillero* obtenerCasillero(int posicionX, int posicionY);

	//PRE:
	//POS: Muestra la información general del tablero.
	void mostrarInformacion();


	//PRE: Los límites son un vector de 4 elementos representado por [inferiorX, superiorX, inferiorY, superiorY]
	//POS: Realiza una busqueda del elemento dependiendo de su clase.
	bool buscarPorCuadrante(string clase, int limites[4]);

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

	void crearTablero(int cantidadFilas, int cantidadColumnas);

	void cargarTablero();
};


#endif /* TABLERO_H_ */
