#include "tablero.h"
#include "objeto.h"
#include "ser.h"
#include "elemento.h"

Tablero::Tablero(){
	cantidadFilas = 0;
	cantidadColumnas = 0;
	tablero = nullptr;
	cargarTablero();
}

void Tablero::crearTablero(int cantidadFilas, int cantidadColumnas){
	this -> cantidadFilas = cantidadFilas;
	this -> cantidadColumnas = cantidadColumnas;
	tablero = new Casillero ** [cantidadFilas];

	for (int i = 0; i < cantidadFilas; i++){
		tablero[i] = new Casillero* [cantidadColumnas];
	}
	inicializarTablero();
	establecerCuadrantes();
}

Tablero::Tablero(int cantidadFilas, int cantidadColumnas){
	this -> cantidadFilas = cantidadFilas;
	this -> cantidadColumnas = cantidadColumnas;
	tablero = new Casillero ** [cantidadFilas];

	for (int i = 0; i < cantidadFilas; i++){
		tablero[i] = new Casillero* [cantidadColumnas];
	}
	inicializarTablero();
	establecerCuadrantes();
}


void Tablero::inicializarTablero(){
	for (int i = 0; i < cantidadFilas; i++){
		for (int j = 0; j < cantidadColumnas; j++){
			tablero[i][j] = new Casillero();
		}
	}
}

void Tablero::establecerCuadrantes(){
	int mitadHorizontal = (this -> cantidadFilas) / 2;
	int mitadVertical = (this -> cantidadColumnas) / 2;
	noroeste[0] = 0;
	noroeste[1] = mitadVertical - 1;
	noroeste[2] = 0;
	noroeste[3] = mitadHorizontal - 1;

	noreste[0] = mitadVertical;
	noreste[1] = cantidadColumnas - 1;
	noreste[2] = 0;
	noreste[3] = mitadHorizontal - 1;

	suroeste[0] = 0;
	suroeste[1] = mitadVertical - 1;
	suroeste[2] = mitadHorizontal;
	suroeste[3] = cantidadFilas - 1;

	sureste[0] = mitadVertical;
	sureste[1] = cantidadColumnas - 1;
	sureste[2] = mitadHorizontal;
	sureste[3] = cantidadFilas - 1;

}


void Tablero::mostrarTablero(){
	for (int i = 0; i < cantidadFilas; i++){
		for (int j = 0; j < cantidadColumnas; j++){
			if (obtenerCasillero(j,i)->obtenerTerreno() == "")
				cout << " * ";
			else
				cout << " " << obtenerCasillero(j,i)->obtenerTerreno() << " ";
		}
		cout << endl;
	}
}

void Tablero::mostrarTableroObjetos(){
	for (int i = 0; i < cantidadFilas; i++){
		for (int j = 0; j < cantidadColumnas; j++){
			if (obtenerCasillero(j,i)->hayPersonaje())
				cout << " " << obtenerCasillero(j,i)->obtenerPersonaje()->obtenerSimbolo() << " ";

			else if (obtenerCasillero(j,i)->hayElemento())
				cout << " " << obtenerCasillero(j,i)->obtenerElemento()->obtenerSimbolo() << " ";

			else
				cout << " * ";
		}
		cout << endl;
	}
}


bool Tablero::esPosicionValida(int posicionX, int posicionY){
	return (posicionX >= 0 && posicionX < cantidadColumnas && posicionY >= 0 && posicionY < cantidadFilas);
}


Casillero* Tablero::obtenerCasillero(int posicionX, int posicionY){
	return tablero[posicionY][posicionX];
}


void Tablero::agregarDato(int posicionX, int posicionY, Ser* nuevoPersonaje){
	tablero[posicionY][posicionX]->asignarPersonaje(nuevoPersonaje);
}

void Tablero::agregarDato(int posicionX, int posicionY, Elemento* nuevoElemento){
	tablero[posicionY][posicionX]->asignarElemento(nuevoElemento);
}

int* Tablero::getNoroeste(){
	return this -> noroeste;
}


int* Tablero::getNoreste(){
	return this -> noreste;
}

int* Tablero::getSuroeste(){
	return this -> suroeste;
}

int* Tablero::getSureste(){
	return this -> sureste;
}

Tablero::~Tablero(){
	for (int i = 0; i < cantidadFilas; i++){
		for (int j = 0; j < cantidadColumnas; j++){
			if (obtenerCasillero(j,i)->hayPersonaje()){
				Ser* aux = obtenerCasillero(j,i)->obtenerPersonaje();
				delete aux;
			}
			else if (obtenerCasillero(j,i)->hayElemento()){
				Elemento* aux = obtenerCasillero(j,i)->obtenerElemento();
				delete aux;
				}
			delete tablero[i][j];
		}
	}

	for (int i = 0; i < cantidadFilas; i++){
		delete [] tablero[i];
	}
	delete []tablero;
}

void Tablero::cargarTablero(){
	   std::ifstream archivo;
	   archivo.open("tablero.txt", std::ios::in);
	   std::string dimensionXStr;
	   std::string dimensionYStr;
	   std::string cadenaTerreno;
	   int fila; int col;

	   if (archivo.is_open()){
		   getline(archivo,dimensionXStr,' ');
		   getline(archivo,dimensionYStr);
		   fila = stoi(dimensionXStr);
	    	col = stoi(dimensionYStr);
	    	crearTablero(fila, col);

	    	int columnaActual = 0;
	    	int filaActual = 0;
	    	int longitud;
	    	std::string terrenoActual;
	    	while (!archivo.eof()){
	    		getline(archivo, cadenaTerreno);
	    		longitud = cadenaTerreno.size();

	    		for (int indiceTerrenoActual = 0; indiceTerrenoActual < longitud; indiceTerrenoActual++){

	    			if (cadenaTerreno[indiceTerrenoActual] != ','){
	    				filaActual = indiceTerrenoActual/2;
	    				terrenoActual = cadenaTerreno[indiceTerrenoActual];
	    				obtenerCasillero(filaActual,columnaActual)->asignarTerreno(terrenoActual);
	    			}
	    		}
	    		columnaActual++;
	    	}
	   }
	   archivo.close();
}


void Tablero::eliminarDato(int posicionX, int posicionY){    //Corregir, eliminar desde el casillero
	Casillero* aux = obtenerCasillero(posicionX, posicionY);

	if (aux->hayPersonaje()){
		Ser* personajeAEliminar = aux->obtenerPersonaje();
		aux->quitarPersonaje();
		delete personajeAEliminar;
	}
	else if (aux->hayElemento()){
		Elemento* elementoAEliminar = aux->obtenerElemento();
		aux->quitarElemento();
		delete elementoAEliminar;
	}
}

















