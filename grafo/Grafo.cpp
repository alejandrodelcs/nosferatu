#include "Grafo.h"
#include <iostream>

Grafo::Grafo() {
    matrizDeAdyacenciaHumanos = nullptr;
    matrizDeAdyacenciaCazadores = nullptr;
    matrizDeAdyacenciaVampiros = nullptr;
    matrizDeAdyacenciaZombies = nullptr;
    vertices = new Lista<Casillero*>();
    floyd = new Floyd(vertices);
//    floydCazadores = new Floyd(vertices);
//    floydVampiros = new Floyd(vertices);
//    floydZombies = new Floyd(vertices);
}

void Grafo::agregarVertice(Casillero* nuevoVertice) {
    agrandarMatrizDeAdyacencia(); //Agrandar todas las matrices de adyacencia.
    vertices -> agregarDato(nuevoVertice);
}

void Grafo::mostrarGrafo(string clase) {
    mostrarVertices();
    mostrarMatrizAdyacencia(clase);
}

void Grafo::agregarCamino(Casillero* origen, Casillero* destino, int pesoOrigen, int pesoDestino, string clase) {  //Origen y destino serían los casilleros o las posiciones?
	int** matrizAModificar = devolverMatrizSegunClase(clase);
	int posicionOrigen = vertices ->obtenerPosicion(origen);		  //Creo que los casilleros.
    int posicionDestino = vertices ->obtenerPosicion(destino);

    if(posicionOrigen == POSICION_NO_ENCONTRADA){
        cout << "El vertice " << origen << " no existe en el grafo" << endl;
    }
    if(posicionDestino == POSICION_NO_ENCONTRADA){
        cout << "El vertice " << destino << " no existe en el grafo" << endl;
    }

    if(!(posicionDestino== POSICION_NO_ENCONTRADA || posicionOrigen == POSICION_NO_ENCONTRADA)) {  //Esto hay que modificarlo
        //matrizDeAdyacencia[posicionOrigen][posicionDestino] = peso;							//pq sirve para grafo no dirigido
        //matrizDeAdyacencia[posicionDestino][posicionOrigen] = peso;
        matrizAModificar[posicionOrigen][posicionDestino] = pesoDestino;
        matrizAModificar[posicionDestino][posicionOrigen] = pesoOrigen;
    }
}

void Grafo::caminoMinimo(Casillero* origen, Casillero* destino) {
    int posicionOrigen = vertices ->obtenerPosicion(origen);
    int posicionDestino = vertices ->obtenerPosicion(destino);

    if(posicionOrigen == POSICION_NO_ENCONTRADA){
        cout << "El vertice " << origen << " no existe en el grafo" << endl;
    }
    if(posicionDestino == POSICION_NO_ENCONTRADA){
        cout << "El vertice " << destino << " no existe en el grafo" << endl;
    }

    caminoMinimo(posicionOrigen, posicionDestino);
}

void Grafo::agrandarMatrizDeAdyacencia() {
    int** matrizAuxiliar;
    int nuevaCantidadDeVertices = vertices->obtenerLargo() + 1;

    matrizAuxiliar = new int*[nuevaCantidadDeVertices];
    for(int i = 0; i < nuevaCantidadDeVertices; i++){
        matrizAuxiliar[i] = new int[nuevaCantidadDeVertices];
    }

    copiarMatrizAdyacente(matrizAuxiliar);
    inicializarNuevoVertice(matrizAuxiliar);
    liberarMatrizAdyacencia();
    matrizDeAdyacenciaHumanos = matrizAuxiliar;
}

void Grafo::copiarMatrizAdyacente(int** nuevaAdyacente) {
    for(int i = 0; i < vertices -> obtenerLargo(); i++){
        for(int j = 0; j < vertices -> obtenerLargo(); j++){
            nuevaAdyacente[i][j] = matrizDeAdyacenciaHumanos[i][j];
        }
    }
}


//Al agregar el nuevo vertice, hace que la nueva columna de la matriz y
//la nueva fila sean infinitos, excepto en su posicion que lo inicia en 0.
void Grafo::inicializarNuevoVertice(int** nuevaAdyacente) {
    for(int i = 0; i < vertices -> obtenerLargo(); i++){
        nuevaAdyacente[vertices -> obtenerLargo()][i] = INFINITO;
        nuevaAdyacente[i][vertices -> obtenerLargo()] = INFINITO;
    }
    nuevaAdyacente[vertices -> obtenerLargo()][vertices -> obtenerLargo()] = 0;
}

void Grafo::liberarMatrizAdyacencia() {
    for(int i = 0; i < vertices -> obtenerLargo(); i++){
        delete[] matrizDeAdyacenciaHumanos[i];
    }
    delete[] matrizDeAdyacenciaHumanos;
}

void Grafo::liberarMatricesAdyacencia(){
    for(int i = 0; i < vertices -> obtenerLargo(); i++){
        delete[] matrizDeAdyacenciaCazadores[i];
        delete[] matrizDeAdyacenciaVampiros[i];
        delete[] matrizDeAdyacenciaZombies[i];
    }
    delete[] matrizDeAdyacenciaCazadores;
    delete[] matrizDeAdyacenciaVampiros;
    delete[] matrizDeAdyacenciaZombies;
}

Grafo::~Grafo() {
    liberarMatrizAdyacencia();
    liberarMatricesAdyacencia();
    matrizDeAdyacenciaHumanos = nullptr;
    delete vertices;
    delete floyd;
//    delete floydCazadores;
//    delete floydVampiros;
//    delete floydZombies;
}

void Grafo::mostrarVertices() {
    cout << "Lista de vértices: [";
    for(int i = 0; i < vertices -> obtenerLargo(); i++){
        cout << vertices -> consulta(i + 1);
        if(i + 1 != vertices -> obtenerLargo()){
            cout << ", ";
        }
    }
    cout << "]" << endl;
}

void Grafo::mostrarMatrizAdyacencia(string clase) {
	int** matrizAMostrar = devolverMatrizSegunClase(clase);
    cout << "Matriz de adyacencia de clase: " << clase << endl;
    for(int i = 0; i < vertices -> obtenerLargo(); i++){
        for(int j = 0; j < vertices -> obtenerLargo() * 2; j++) {
            if(j == vertices -> obtenerLargo() * 2 - 1){
                cout << endl;
            } else if(j % 2 == 0){
                if(matrizAMostrar[i][j/2] == INFINITO){
                    cout << "∞";
                } else {
                    cout << matrizAMostrar[i][j/2];
                }
            } else{
                cout << "|";
            }
        }
    }
    cout << endl;
}

void Grafo::caminoMinimo(int origen, int destino) {
    floyd -> caminoMinimo(origen, destino);
}

//Modificar segun la matriz correspondiente(humano, cazador, zombie, vampiro)
void Grafo::calcularMatricesFloyd() {
    floyd -> calcularMatrices(matrizDeAdyacenciaHumanos);
//    floyd->calcularMatrices(matrizDeAdyacenciaCazadores);
//    floyd->calcularMatrices(matrizDeAdyacenciaVampiros);
//    floyd->calcularMatrices(matrizDeAdyacenciaZombies);
}


void Grafo::agregarVerticesTablero(Tablero* tablero){
	int cantidadFilas = tablero->obtenerCantidadFilas();
	int cantidadColumnas = tablero->obtenerCantidadColumnas();
	for (int i = 0; i < cantidadFilas; i++){
		for (int j = 0; j < cantidadColumnas; j++){
			agregarVertice(tablero->obtenerCasillero(j, i));
		}
	}
	crearMatricesAdyacentes(matrizDeAdyacenciaCazadores);
	copiarMatrizAdyacente(matrizDeAdyacenciaCazadores);
	crearMatricesAdyacentes(matrizDeAdyacenciaVampiros);
	copiarMatrizAdyacente(matrizDeAdyacenciaVampiros);
	crearMatricesAdyacentes(matrizDeAdyacenciaZombies);
	copiarMatrizAdyacente(matrizDeAdyacenciaZombies);
}


void Grafo::crearMatricesAdyacentes(int** &nuevaMatriz){
	int cantidadVertices = vertices->obtenerLargo();
    nuevaMatriz = new int*[cantidadVertices];
    for(int i = 0; i < cantidadVertices; i++){
        nuevaMatriz[i] = new int[cantidadVertices];
    }
}


void Grafo::cargarCaminosTablero(Tablero* tablero, string clase){
	int cantidadFilas = tablero->obtenerCantidadFilas();
	int cantidadColumnas = tablero->obtenerCantidadColumnas();
	for (int i = 0; i < cantidadFilas - 1; i++){
		for (int j = 0; j < cantidadColumnas - 1; j++){
			int pesoOrigen = obtenerPesoCasillero(clase, tablero->obtenerCasillero(j, i));
			int pesoDestino = obtenerPesoCasillero(clase, tablero->obtenerCasillero(j+1, i));
			agregarCamino(tablero->obtenerCasillero(j, i), tablero->obtenerCasillero(j+1, i), pesoOrigen, pesoDestino, clase);
			pesoDestino = obtenerPesoCasillero(clase,tablero->obtenerCasillero(j, i+1));
			agregarCamino(tablero->obtenerCasillero(j, i), tablero->obtenerCasillero(j, i+1), pesoOrigen, pesoDestino, clase);
		}
	}
	cargarCaminosUltimaColumna(tablero, clase);
	cargarCaminosUltimaFila(tablero, clase);
}

void Grafo::cargarCaminosUltimaColumna(Tablero* tablero, string clase){
	int cantidadFilas = tablero->obtenerCantidadFilas();
	int cantidadColumnas = tablero->obtenerCantidadColumnas();
	int ultimaColumna = cantidadColumnas - 1;
	for (int i = 0; i < cantidadFilas - 1; i++){
			int pesoOrigen = obtenerPesoCasillero(clase, tablero->obtenerCasillero(ultimaColumna, i));
			int pesoDestino = obtenerPesoCasillero(clase, tablero->obtenerCasillero(ultimaColumna, i+1));
			agregarCamino(tablero->obtenerCasillero(ultimaColumna, i), tablero->obtenerCasillero(ultimaColumna, i+1), pesoOrigen, pesoDestino, clase);
	}
}

void Grafo::cargarCaminosUltimaFila(Tablero* tablero, string clase){
	int cantidadFilas = tablero->obtenerCantidadFilas();
	int cantidadColumnas = tablero->obtenerCantidadColumnas();
	int ultimaFila = cantidadFilas - 1;
	for (int i = 0; i < cantidadColumnas - 1; i++){
			int pesoOrigen = obtenerPesoCasillero(clase, tablero->obtenerCasillero(i, ultimaFila));
			int pesoDestino = obtenerPesoCasillero(clase, tablero->obtenerCasillero(i+1, ultimaFila));
			agregarCamino(tablero->obtenerCasillero(i, ultimaFila), tablero->obtenerCasillero(i+1, ultimaFila), pesoOrigen, pesoDestino, clase);
	}
}

int Grafo::obtenerPesoCasillero(string clase, Casillero* casillero){
	int peso;
	if (casillero->obtenerTerreno() == "M"){
		if (clase == "humano")
			peso = 2;
		else if (clase == "cazador")
			peso = 0;
		else
			peso = 1;
	}
	else if (casillero->obtenerTerreno() == "P"){
		if (clase == "humano" || clase == "cazador")
			peso = 2;
		else if (clase == "vampiro")
			peso = 0;
		else
			peso = 1;
	}
	else if (casillero->obtenerTerreno() == "L"){
		if (clase == "humano" || clase == "cazador")
			peso = 0;
		else if (clase == "vampiro")
			peso = 1;
		else
			peso = 2;
	}
	else if (casillero->obtenerTerreno() == "V"){
		if (clase == "humano" || clase == "cazador")
			peso = 1;
		else if (clase == "vampiro")
			peso = 2;
		else
			peso = 0;
	}
	else if (casillero->obtenerTerreno() == "C"){
		peso = 1;
	}
	else 				//Casillero con vacío (O)
		peso = 15;

	return peso;
}

int** Grafo::devolverMatrizSegunClase(string clase){
	int** matrizADevolver;
	if (clase == HUMANO)
		matrizADevolver = matrizDeAdyacenciaHumanos;
	else if (clase == CAZADOR)
		matrizADevolver = matrizDeAdyacenciaCazadores;
	else if (clase == VAMPIRO)
		matrizADevolver = matrizDeAdyacenciaVampiros;
	else
		matrizADevolver = matrizDeAdyacenciaZombies;
	return matrizADevolver;
}

