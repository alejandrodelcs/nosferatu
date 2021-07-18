#include "tablero.h"
#include "objeto.h"

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
	noroeste[0] = 1;
	noroeste[1] = mitadVertical;
	noroeste[2] = 1;
	noroeste[3] = mitadHorizontal;

	noreste[0] = mitadVertical + 1;
	noreste[1] = cantidadColumnas;
	noreste[2] = 1;
	noreste[3] = mitadHorizontal;

	suroeste[0] = 1;
	suroeste[1] = mitadVertical;
	suroeste[2] = mitadHorizontal + 1;
	suroeste[3] = cantidadFilas;

	sureste[0] = mitadVertical + 1;
	sureste[1] = cantidadColumnas;
	sureste[2] = mitadHorizontal + 1;
	sureste[3] = cantidadFilas;

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




bool Tablero::esPosicionVacia(int posicionX, int posicionY){
	posicionX --;
	posicionY --;
	bool posicionVacia = false;

	if (tablero[posicionY][posicionX] == nullptr){
		posicionVacia = true;
	}

	return posicionVacia;
}


bool Tablero::esPosicionValida(int posicionX, int posicionY){
	posicionX --;
	posicionY --;
	bool posicionValida = false;

	if (posicionX >= 0 && posicionX < cantidadColumnas && posicionY >= 0 && posicionY < cantidadFilas)
		posicionValida = true;

	return posicionValida;
}


Casillero* Tablero::obtenerCasillero(int posicionX, int posicionY){
	Casillero* auxiliar;
	auxiliar = tablero[posicionY][posicionX];
	return auxiliar;
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
	for (int i = 1; i <= cantidadFilas; i++){
		for (int j = 1; j <= cantidadColumnas; j++)
			if (! esPosicionVacia(j,i))
				delete tablero[i-1][j-1];
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

	    	int i = 0;
	    	int k = 0;
	    	int longitud;
	    	std::string terrenoActual;
	    	while (!archivo.eof()){
	    		getline(archivo, cadenaTerreno);
	    		longitud = cadenaTerreno.size();

	    		for (int j = 0; j < longitud; j++){

	    			if (cadenaTerreno[j] != ','){
	    				k = j/2;
	    				terrenoActual = cadenaTerreno[j];
	    				obtenerCasillero(k,i)->asignarTerreno(terrenoActual);
	    			}
	    		}
	    		i++;
	    	}
	   }
	   archivo.close();
}



