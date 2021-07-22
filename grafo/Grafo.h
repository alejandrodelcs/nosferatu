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
    int** matrizDeAdyacenciaHumanos;
    int** matrizDeAdyacenciaCazadores;
    int** matrizDeAdyacenciaVampiros;
    int** matrizDeAdyacenciaZombies;
    Lista<Casillero*> * vertices;
    Floyd * floyd;
//    Floyd * floydCazadores;
//    Floyd * floydVampiros;
//    Floyd * floydZombies;


/*MÉTODOS*/

    //pre: tienen que existir tanto el origen como el destino. Ademas se deben haber calculado las matrices de Floyd
    //post: muestra el camino minimo entre el origen y el destino
    void caminoMinimo(int origen, int destino);

    //post: agranda dinamicamente la matriz de adyacencia
    void agrandarMatrizDeAdyacencia();

    //pre: la matriz que se le envie ya debe tener memoria reservada
    //post: copia la matriz de adyacencia en la nueva matriz
    void copiarMatrizAdyacente(int** nuevaAdyacente);

    //post inicializa un nuevo vertice en la matriz de adyacencia con un valor de infinito
    void inicializarNuevoVertice(int** nuevaAdyacente);

    //post libera la memoria de la matriz de adyacencia
    void liberarMatrizAdyacencia();

    void liberarMatricesAdyacencia();

    void crearMatricesAdyacentes(int** &nuevaMatriz);

    //post: imprime por pantalla los vertices del grafo
    void mostrarVertices();

    //post: imprime por pantalla la matriz de adyacencia
    void mostrarMatrizAdyacencia(string clase);

    int** devolverMatrizSegunClase(string clase);
public:

    Grafo();
    //PRE: No hay vertices repetidos en nombre
    //post: agrega un nuevo vertice al grafo
    void agregarVertice(Casillero* nuevoVertice);

    //Post: muestra por terminal el camino mínimo desde un origen a un destino
    void caminoMinimo(Casillero* origen, Casillero* destino);

    //pre: el peso es un valor positivo
    //post: Ajusta la matriz de adyacencia con el peso ingresado
    void agregarCamino(Casillero* origen, Casillero* destino, int pesoOrigen, int pesoDestino, string clase);

    //post: imprime por pantalla el grafo
    void mostrarGrafo(string clase);

    ~Grafo();

    //post: calcula la matrices que requiere el metodo de floyd para funcionar
    void calcularMatricesFloyd();

    //PRE:
    //POS: Agrega cada casillero del tablero como vertice del grafo
    void agregarVerticesTablero(Tablero* tablero);

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
    //POS: Obtiene el peso del casillero segun el costo de cada clase
    int obtenerPesoCasillero(string clase, Casillero* casillero);

};


#endif //GRAFOS_GRAFO_H
