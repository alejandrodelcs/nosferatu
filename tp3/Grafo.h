#ifndef GRAFOS_GRAFO_H
#define GRAFOS_GRAFO_H
#include <string>
#include "casillero.h"
#include "Floyd.h"
#include "tablero.h"

const int INFINITO = 99999999;
const string HUMANO = "humano";
const string CAZADOR = "cazador";
const string VAMPIRO = "vampiro";
const string ZOMBIE = "zombie";

using namespace std;

class Grafo {
/*ATRIBUTOS*/
private:
    int** matrizDeAdyacencia;
    int cantidadVertices;
    Floyd * floyd;


/*MÉTODOS*/

    //PRE:
    //POS: Obtiene la cantidad de casilleros del tablero y por ende la cantidad de vértices del grafo
    int obtenerLargo(Tablero* tablero);

    //PRE:
    //POS: Inicializa la matriz con 0 en la diagonal e infinito en el resto
    void inicializarMatrizAdyacencia();

    //pre: tienen que existir tanto el origen como el destino. Ademas se deben haber calculado las matrices de Floyd
    //post: muestra el camino minimo entre el origen y el destino
    void caminoMinimo(int origen, int destino, Tablero* tablero, Lista<Coordenadas*>* movimientos, int &energiaNecesaria);

    //post libera la memoria de la matriz de adyacencia
    void liberarMatrizAdyacencia();

    //post: imprime por pantalla la matriz de adyacencia
    void mostrarMatrizAdyacencia();

public:

    Grafo();

    //PRE:
    //POS: crea una matriz de tamaño cantidadVertices*cantidadVertices donde cantidadVertices es el resultado
    //     de hacer la cantidadFilas*cantidadColumnas del tablero.
    void crearMatrizAdyacencia(Tablero* tablero);

    //Post: muestra por terminal el camino mínimo desde un origen a un destino
    void caminoMinimo(Casillero* origen, Casillero* destino, Tablero* tablero, Lista<Coordenadas*>* movimientos, int &energiaNecesaria);

    //pre: el peso es un valor positivo
    //post: Ajusta la matriz de adyacencia con el peso ingresado
    void agregarCamino(Casillero* origen, Casillero* destino, int pesoOrigen, int pesoDestino, string clase, Tablero* tablero);

    //post: imprime por pantalla el grafo
    void mostrarGrafo();

    ~Grafo();

    //post: calcula la matrices que requiere el metodo de floyd para funcionar
    void calcularMatricesFloyd();

    //PRE:
    //POS: Genera un camino entre cada casillero y su derecho y entre el casillero y su inferior y lo carga a la matriz de adyacencia
    //IMPORTANTE: Queda la ultima fila y columna sin cargar
    void cargarCaminosTablero(Tablero* tablero, string clase);

    //PRE:
    //POS: Carga la ultima fila y columna que quedaron sin cargar en cargarCaminosTablero.
    void cargarCaminosUltimaColumna(Tablero* tablero, string clase);

    //PRE:
    //POS: Carga la ultima fila y columna que quedaron sin cargar en cargarCaminosTablero.
    void cargarCaminosUltimaFila(Tablero* tablero, string clase);

    //PRE:
    //POS: Obtiene la posicion que ocuparía un casillero del tablero en una lista de vertices.
    //     Sirve para ubicarlos en las posiciones de la matriz de adyacencia.
    int obtenerPosicion(Tablero* tablero, Casillero* casillero);

};


#endif //GRAFOS_GRAFO_H
