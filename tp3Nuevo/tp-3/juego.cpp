#include "juego.h"


//Juego::Juego(){
//	this->personajesBuenos = nullptr;
//	this->personajesMalos = nullptr;
//}


//void Juego::inicializar(Lista<Ser*>* personajesBuenos, Lista<Ser*>* personajesMalos){
//	this->personajesBuenos = personajesBuenos;
//	this->personajesMalos = personajesMalos;
//}


void Juego::crearEquipos(Tablero* tablero){
	for (int i = 0; i < tablero->obtenerCantidadFilas(); i++){
		for (int j = 0; j < tablero->obtenerCantidadColumnas(); j++){
			if (tablero->obtenerCasillero(j, i)->hayPersonaje()){
				Ser* personajeAAgregar = tablero->obtenerCasillero(j, i)->obtenerPersonaje();
				if (personajeAAgregar->obtenerId() < LIMITE_ID_PERSONAJES_BUENOS)
					personajesBuenos->agregarDato(personajeAAgregar);
				else
					personajesMalos->agregarDato(personajeAAgregar);
			}
		}
	}
	//inicializar(personajesBuenos, personajesMalos);
}

void Juego::mostrarCantidadPersonajes(){
	std::cout << "El equipo de los buenos tiene " << personajesBuenos->obtenerLargo() << " personajes." << std::endl;
	std::cout << "El equipo de los malos tiene " << personajesMalos->obtenerLargo() << " personajes." << std::endl;

	//PARA VER QUE LAS LISTAS SE FORMEN BIEN
	personajesBuenos->reiniciarActual();
	personajesMalos->reiniciarActual();
	while (personajesBuenos->haySiguiente())
		personajesBuenos->siguiente()->mostrar();
	std::cout << std::endl;
	while (personajesMalos->haySiguiente())
		personajesMalos->siguiente()->mostrar();
}


/*
void Juego::comenzarJuego(){
	elegirBando();
	DecidirPrimerTurno();
	jugar();
}

//Este debería variar dependiendo de quién empiece
void Juego::jugar(){
	personajesBuenos->reiniciarActual();
	personajesMalos->reiniciarActual();
	while (personajesBuenos->haySiguiente()){
		mostrarMenu()
		elegirOpcion(personajesBuenos->siguiente())
	}
	while (personajesMalos->haySiguiente()){
		mostrarMenu()
		elegirOpcion(personajesMalos->siguiente())
	}
	cambiarTurno();
}


void Juego::mostrarMenu(){
	std::cout << "Elija una opcion:\n"
			"1) Atacar.\n"
			"2) Defenderse.\n"
			"3) Moverse. \n"
			"4) Pasar. \n";
}


void elegirOpcion(Ser* personaje){
	int opcion = pedirOpcion();
	validarOpcion(opcion, OPCION_MINIMA, OPCION_MAXIMA);
	if (opcion == 1)
		atacar();
	else if (opcion == 2)
		defender();
	else if (opcion == 3)
		moverse();
	else
		pasar();

}

void validarOpcion(int &opcion,int opcionMinima,int opcionMaxima){
	do{
		std::cout << "Ingrese una opción entre " << opcionMinima << " y " << opcionMaxima << std::endl;
		cin >> opcion;
	}while (opcion < opcionMinima || opcion > opcionMaxima);
}


int pedirOpcion(){
	int opcion;
	std::cout << "Ingrese una opcion" << std::endl;
	cin >> opcion;
	return opcion;

}
*/

Juego::~Juego(){
	delete personajesBuenos;
	delete personajesMalos;
}
