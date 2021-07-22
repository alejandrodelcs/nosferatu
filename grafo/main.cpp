#include <iostream>

#include "Grafo.h"
#include "casillero.h"
#include "tablero.h"

int main() {


	Tablero* nuevoTablero = new Tablero();

	nuevoTablero->mostrarTablero();


    Grafo grafo;
    grafo.agregarVerticesTablero(nuevoTablero);
    grafo.cargarCaminosTablero(nuevoTablero, HUMANO);
    grafo.cargarCaminosTablero(nuevoTablero, CAZADOR);
    grafo.cargarCaminosTablero(nuevoTablero, VAMPIRO);
    grafo.cargarCaminosTablero(nuevoTablero, ZOMBIE);
    grafo.mostrarGrafo(HUMANO);
    cout << endl;
    grafo.mostrarGrafo(CAZADOR);
    cout << endl;
    grafo.mostrarGrafo(VAMPIRO);
    cout << endl;
    grafo.mostrarGrafo(ZOMBIE);


    //grafo.mostrarGrafo();
    grafo.calcularMatricesFloyd();
    grafo.caminoMinimo(nuevoTablero->obtenerCasillero(0,0), nuevoTablero->obtenerCasillero(0,4));

	delete nuevoTablero;

	return 0;
}
