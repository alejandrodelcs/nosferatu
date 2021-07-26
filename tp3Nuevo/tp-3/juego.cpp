#include "juego.h"


//Juego::Juego(){
//	this->personajesBuenos = nullptr;
//	this->personajesMalos = nullptr;
//	Lista<Ser*>* jugador1 = nullptr;
//	Lista<Ser*>* jugador2 = nullptr;
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


void Juego::elegirBando(){
	int opcion;
	std::cout << "Jugador 1, elija un bando:\n1)Personajes buenos\n2)Personajes malos\n";
	cin >> opcion;
	validarOpcion(opcion, 1, 2);
	if (opcion == 1){
		jugador1 = personajesBuenos;
		jugador2 = personajesMalos;
		std::cout << "Personaje1->Buenos" << std::endl;
		jugador1->imprimirLista();
	}
	else{
		jugador1 = personajesMalos;
		jugador2 = personajesBuenos;
		std::cout << "Personaje1->Malos" << std::endl;
		jugador1->imprimirLista();

	}
}


void Juego::comenzarJuego(Tablero* tablero){
	cargarGrafos(tablero);
	bool continuar = true;
	elegirBando();
	int primero = decidirPrimerTurno();
	if (primero == 1){
		while (continuar)
			jugar(jugador1, jugador2, continuar, tablero);
	}
	else{
		while (continuar)
			jugar(jugador2, jugador1, continuar, tablero);
	}
}

void Juego::cargarGrafos(Tablero* tablero){
	grafoHumanos.crearMatrizAdyacencia(tablero);
	grafoHumanos.cargarCaminosTablero(tablero, HUMANO);
	grafoHumanos.calcularMatricesFloyd();

	grafoCazadores.crearMatrizAdyacencia(tablero);
	grafoCazadores.cargarCaminosTablero(tablero, CAZADOR);
	grafoCazadores.calcularMatricesFloyd();

	grafoVampiros.crearMatrizAdyacencia(tablero);
	grafoVampiros.cargarCaminosTablero(tablero, VAMPIRO);
	grafoVampiros.calcularMatricesFloyd();

	grafoZombies.crearMatrizAdyacencia(tablero);
	grafoZombies.cargarCaminosTablero(tablero, ZOMBIE);
	grafoZombies.calcularMatricesFloyd();

	//mostrarGrafos();
}

void Juego::mostrarGrafos(){
	grafoHumanos.mostrarGrafo();
	grafoCazadores.mostrarGrafo();
	grafoVampiros.mostrarGrafo();
	grafoZombies.mostrarGrafo();
}

int Juego::decidirPrimerTurno(){
	int primero = rand() % (2 - 1 +1) + 1;
	return primero;
}


void Juego::jugar(Lista<Ser*>* primerJugador, Lista<Ser*>* segundoJugador, bool &continuar, Tablero* tablero){
	primerJugador->reiniciarActual();
	segundoJugador->reiniciarActual();
	cout << "--------PERSONAJES PRIMER JUGADOR--------\n";
	while (primerJugador->haySiguiente()){
		Ser* personajeAJugar = primerJugador->siguiente();
		mostrarMenuPersonaje(personajeAJugar);
		elegirOpcion(personajeAJugar, tablero);
	}
	cout << "--------PERSONAJES SEGUNDO JUGADOR--------\n";
	while (segundoJugador->haySiguiente()){
		Ser* personajeAJugar = segundoJugador->siguiente();
		mostrarMenuPersonaje(personajeAJugar);
		elegirOpcion(personajeAJugar, tablero);
	}
	//cambiarTurno();
	preguntarSiDeseaContinuar(continuar);
}

void Juego::preguntarSiDeseaContinuar(bool &continuar){
	int opcion = true;
	std::cout << "\nDesea continuar?\n1) Si\n2) No" << std::endl;
	cin >> opcion;
	if (opcion == 2)
		continuar = false;
}

void Juego::mostrarMenuPersonaje(Ser* personajeAJugar){
	std::cout << std::endl;
	personajeAJugar->mostrar();
	std::cout << "Elija una opcion:\n"
			"1) Atacar.\n"
			"2) Defenderse.\n"
			"3) Moverse. \n"
			"4) Pasar. \n";
}


void Juego::elegirOpcion(Ser* personaje, Tablero* tablero){
	tablero->mostrarTableroObjetos();
	int opcion = pedirOpcion();
	validarOpcion(opcion, OPCION_MINIMA, OPCION_MAXIMA);
	if (opcion == 1)
		std::cout << "Ataco" << std::endl; //atacar(personaje, tablero); Le pregunta donde quiere atacar?
	else if (opcion == 2)
		std::cout << "Defiendo" << std::endl;//defender(personaje, tablero);
	else if (opcion == 3)
		moverse(personaje, tablero);
	else
		pasarTurno();
}

void Juego::pasarTurno(){}

int Juego::pedirOpcion(){
	int opcion;
	std::cout << "Ingrese una opcion: ";
	cin >> opcion;
	return opcion;
}

void Juego::validarOpcion(int &opcion,int opcionMinima,int opcionMaxima){
	while (opcion < opcionMinima || opcion > opcionMaxima){
		std::cout << "Ingrese una opción entre " << opcionMinima << " y " << opcionMaxima << std::endl;
		cin >> opcion;
	}
}


void Juego::moverse(Ser* personaje, Tablero* tablero){
	int energiaNecesaria = 0;
	Lista<Coordenadas*>* movimientos = new Lista<Coordenadas*>();
	int posicionInicialX = personaje->obtenerFila();
	int posicionInicialY = personaje->obtenerColumna();
	int posicionFinalX;
	int posicionFinalY;
	obtenerNuevaPosicion(posicionFinalX, posicionFinalY);
	if (! tablero->esPosicionValida(posicionFinalX, posicionFinalY) || tablero->obtenerCasillero(posicionFinalX, posicionFinalY)->hayPersonaje()){
		std::cout << "La posición es inválida o está ocupada" << std::endl;
	}
	else{
		if (personaje->obtenerSimbolo() == "h")
			grafoHumanos.caminoMinimo(tablero->obtenerCasillero(posicionInicialX,posicionInicialY), tablero->obtenerCasillero(posicionFinalX, posicionFinalY), tablero, movimientos, energiaNecesaria);
		else if (personaje->obtenerSimbolo() == "H" || personaje->obtenerSimbolo() == "W")
			grafoCazadores.caminoMinimo(tablero->obtenerCasillero(posicionInicialX,posicionInicialY), tablero->obtenerCasillero(posicionFinalX, posicionFinalY), tablero, movimientos, energiaNecesaria);
		else if (personaje->obtenerSimbolo() == "v" || personaje->obtenerSimbolo() == "N" || personaje->obtenerSimbolo() == "V")
			grafoVampiros.caminoMinimo(tablero->obtenerCasillero(posicionInicialX,posicionInicialY), tablero->obtenerCasillero(posicionFinalX, posicionFinalY), tablero, movimientos, energiaNecesaria);
		else
			grafoZombies.caminoMinimo(tablero->obtenerCasillero(posicionInicialX,posicionInicialY), tablero->obtenerCasillero(posicionFinalX, posicionFinalY), tablero, movimientos, energiaNecesaria);
	}
	//if (energiaNecesaria > personaje->obtenerEnergia())
	//	std::cout << "No hay energía suficiente para moverse a esa posición.\n";
	if (! esCaminoValido(movimientos, tablero))
		std::cout << "El camino está bloqueado\n";
	else{

		movimientos->reiniciarActual();
		if (movimientos->haySiguiente())
			movimientos->siguiente(); //coord 4,4

		while (movimientos->haySiguiente()){
			tablero->mostrarTableroObjetos();
			std::cout << std::endl;

			Coordenadas* coordenadasActual = movimientos->siguiente(); //coord 4,5
			tablero->obtenerCasillero(coordenadasActual->obtenerCoordenadaX(), coordenadasActual->obtenerCoordenadaY())->asignarPersonaje(personaje);
			tablero->obtenerCasillero(personaje->obtenerFila(), personaje->obtenerColumna())->quitarPersonaje();
			personaje->asignarColumna(coordenadasActual->obtenerCoordenadaY());
			personaje->asignarFila(coordenadasActual->obtenerCoordenadaX());
		}
	}
	eliminarListaMovimientos(movimientos);
}


//void Juego::calcularCamino(Ser* personaje, Tablero* tablero, Lista<Coordenadas*>* movimientos, int &energiaNecesaria){
//	if (personaje->obtenerSimbolo() == "h")
//				grafoHumanos.caminoMinimo(tablero->obtenerCasillero(posicionInicialX,posicionInicialY), tablero->obtenerCasillero(posicionFinalX, posicionFinalY), tablero, movimientos, energiaNecesaria);
//			else if (personaje->obtenerSimbolo() == "H" || personaje->obtenerSimbolo() == "W")
//				grafoCazadores.caminoMinimo(tablero->obtenerCasillero(posicionInicialX,posicionInicialY), tablero->obtenerCasillero(posicionFinalX, posicionFinalY), tablero, movimientos, energiaNecesaria);
//			else if (personaje->obtenerSimbolo() == "v" || personaje->obtenerSimbolo() == "N" || personaje->obtenerSimbolo() == "V")
//				grafoVampiros.caminoMinimo(tablero->obtenerCasillero(posicionInicialX,posicionInicialY), tablero->obtenerCasillero(posicionFinalX, posicionFinalY), tablero, movimientos, energiaNecesaria);
//			else
//				grafoZombies.caminoMinimo(tablero->obtenerCasillero(posicionInicialX,posicionInicialY), tablero->obtenerCasillero(posicionFinalX, posicionFinalY), tablero, movimientos, energiaNecesaria);
//}


void Juego::eliminarListaMovimientos(Lista<Coordenadas*>* movimientos){
	movimientos->reiniciarActual();
	while (movimientos->haySiguiente()){
		Coordenadas* coordenadas = movimientos->siguiente();
		delete coordenadas;
	}
	delete movimientos;

}

bool Juego::esCaminoValido(Lista<Coordenadas*>* movimientos, Tablero* tablero){
	bool esValido = true;
	movimientos->reiniciarActual();
	if (movimientos->haySiguiente())
		movimientos->siguiente();
	while (movimientos->haySiguiente() && esValido == true){
		Coordenadas* coordenadasActual = movimientos->siguiente();
		if (tablero->obtenerCasillero(coordenadasActual->obtenerCoordenadaX(), coordenadasActual->obtenerCoordenadaY())->hayPersonaje())
			esValido = false;
	}
	return esValido;
}

void Juego::obtenerNuevaPosicion(int &posicionX, int &posicionY){
	std::cout << "Ingrese una posicionX: ";
	std::cin >> posicionX;
	std::cout << "Ingrese una posicionY: ";
	std::cin >> posicionY;
	posicionX--;
	posicionY--;
}

Juego::~Juego(){
	delete personajesBuenos;
	delete personajesMalos;
}
