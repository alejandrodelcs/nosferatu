#include "Menu.h"
#include <iostream>

Menu::Menu(ABB<string, Objeto*>* diccionarioPersonajes, Tablero* tablero) {
	// TODO Auto-generated constructor stub
	this->opcionPrincipal = 0;
	this->opcionSimulacion = 0;
	this->diccionarioPersonajes = diccionarioPersonajes;
	this->tablero = tablero;
	this->pruebaId = 500;
    iden.inicializar(diccionarioPersonajes);

}

void Menu::mostrarMenuPrincipal(){
	std::cout << "-----MENU PRINCIPAL-----" << std::endl;
	std::cout << "1.Agregar nuevo personaje u objeto (en una posicion determinada)" << std::endl;
	std::cout << "2.Eliminar un personaje u objeto" << std::endl;
	std::cout << "3.Mostrar tablero" << std::endl;
	std::cout << "4.Buscar por cuadrante un personaje u objeto" << std::endl;
	std::cout << "5.Buscar por ID los detalles de un personaje u objeto" << std::endl;
	std::cout << "6.Comenzar simulacion" << std::endl;
	std::cout << "7.Salir" << std::endl;
}


void Menu::procesarOpcionPrincipal(){

	switch(opcionPrincipal){

	case AGREGAR_PERSONAJE_U_OBJETO:
		std::cout << "- AGREGANDO PERSONAJE U OBJETO -" << std::endl;
		agregarDato();
		break;

	case ELIMINAR_PERSONAJE_U_OBJETO:
		std::cout << "- ELIMINANDO PERSONAJE U OBJETO -" << std::endl;
		mostrarTablero();
		eliminarDato();
		break;

	case MOSTRAR_TABLERO:
		std::cout << "- MOSTRANDO TABLERO -" << std::endl;
		mostrarTablero();
		break;

	case BUSCAR_POR_CUADRANTE:
		std::cout << "- BUSCAR POR CUADRANTE -" << std::endl;
		break;

	case BUSCAR_POR_ID:
		std::cout << "- BUSCANDO POR ID -" << std::endl;
		buscarPersonajePorId();
		break;

	case COMENZAR_SIMULACION:{
		std::cout << std::endl;
	    std::cout << "- COMENZANDO SIMULACION - " << std::endl;
	    Juego nuevoJuego;
	    nuevoJuego.crearEquipos(tablero);
	    ingresarOpcionSimulacion();
	    while (opcionSimulacion != SALIR_SIMULACION){
	    	procesarOpcionSimulacion(nuevoJuego);
	    	std::cout << std::endl;
	    	ingresarOpcionSimulacion();
	    }
	    break;
	}

	case SALIR_MENU_PRINCIPAL:
		std::cout << "- SALIENDO -" << std::endl;
		break;

	//default: std::cout << "Dudo que informe esta opcion e.e" << std::endl;
	}
}

void Menu::ingresarOpcionPrincipal(){
	mostrarMenuPrincipal();
	std::cout << "Ingrese una opcion: ";
	std::cin >> opcionPrincipal;
	validarOpcionPrincipal(opcionPrincipal);
}

void Menu::ingresarOpcionSimulacion(){
	mostrarMenuSimulacion();
	std::cout << "Ingrese opcion simulacion: ";
	std::cin >> opcionSimulacion;
	validarOpcionSimulacion(opcionSimulacion);
}

void Menu::validarOpcionPrincipal(int & opcionPrincipal){
	while (opcionPrincipal < AGREGAR_PERSONAJE_U_OBJETO || opcionPrincipal > SALIR_MENU_PRINCIPAL){
		std::cout << "Opcion incorrecta, reingrese: ";
		std::cin >> opcionPrincipal;
	}
}

void Menu::validarOpcionSimulacion(int & opcionSimulacion){
	while (opcionSimulacion < BUSCAR_POR_ID_SIMULACION || opcionSimulacion > SALIR_SIMULACION){
		std::cout << "Opcion simulacion incorrecta, reingrese: ";
		std::cin >> opcionSimulacion;
	}
}

void Menu::mostrarMenuSimulacion(){
	std::cout << "-----MENU SIMULACION-----" << std::endl;
	std::cout << "1.Buscar por ID los detalles de un personaje u objeto en particular" << std::endl;
	std::cout << "2.Mostrar tablero" << std::endl;
	std::cout << "3.Mostrar la cantidad de integrantes de cada bando" << std::endl;
	std::cout << "4. Seleccionar bando" << std::endl;
	std::cout << "5. Salir" << std::endl;
}

int Menu::obtenerOpcionMenuPrincipal(){
	return this->opcionPrincipal;
}

int Menu::obtenerOpcionSimulacion(){
	return this->opcionSimulacion;
}

void Menu::procesarOpcionSimulacion(Juego &nuevoJuego){

	switch(opcionSimulacion){

	case BUSCAR_POR_ID_SIMULACION:
		std::cout << "- BUSCANDO POR ID -(SIMULACION)-" << std::endl;
		buscarPersonajePorId();
		break;

	case MOSTRAR_TABLERO_SIMULACION:
		std::cout << "- MOSTRARNDO EL TABLERO -(SIMULACION)-" << std::endl;
		mostrarTablero();
		break;

	case MOSTRAR_CANTIDAD_DE_INTEGRANTES_DE_UN_BANDO_SIMULACION:
		std:: cout << "MOSTRANDO CANTIDAD DE INTEGRANTES X BANDO -(SIMULACION)" << std::endl;
		nuevoJuego.mostrarCantidadPersonajes();
		break;

	case SELECCIONAR_BANDO_SIMULACION:
		std::cout << "SELECCIONANDO BANDO -(SIMULACION)-" << std::endl;
		nuevoJuego.comenzarJuego(tablero);
		break;

	case SALIR_SIMULACION:
		std::cout << "-SALIENDO SIMULACION-" << std::endl;
		break;

	//default: std:: cout << "Dudo que entre a esta parte de simulacion e.e" << std::endl;
	}
}




//---------------DESDE ACÁ IMPLEMENTACION DE LAS OPCIONES DEL MENÚ----------------------------

void Menu::mostrarTablero(){
	tablero->mostrarTableroObjetos();
}


void Menu::buscarPersonajePorId(){
	string idABuscar;
	std::cout << "Ingrese el Id del personaje que quiere ver: " << std::endl;
	std::cin >> idABuscar;
	if (! diccionarioPersonajes->esta(idABuscar))
		cout << "El personaje u objeto no existe." << std::endl;
	else
		diccionarioPersonajes->buscar(idABuscar)->mostrar();
}

void Menu::eliminarDato(){
	int posicionX = -1;
	int posicionY = -1;
	pedirCoordenadas(posicionX, posicionY);

	if (tablero->esPosicionValida(posicionX, posicionY)){
		Casillero* aux = tablero->obtenerCasillero(posicionX, posicionY);
		if (aux->hayPersonaje()){
			diccionarioPersonajes->eliminarNodo(aux->obtenerPersonaje()->obtenerId());
			tablero->eliminarDato(posicionX, posicionY);
			std::cout << "Personaje eliminado." << std::endl;
		}
		else if (aux->hayElemento()){
			diccionarioPersonajes->eliminarNodo(aux->obtenerElemento()->obtenerId());
			tablero->eliminarDato(posicionX, posicionY);
			std::cout << "Objeto eliminado." << std::endl;
		}
		else
			std::cout << "No hay un personaje u objeto en esta posición." << std::endl;
	}
	else
		std::cout << "La posición está fuera del tablero." << std::endl;
}


void Menu::mostrarOpcionesAAgregar(){
	std::cout << "\n1) Humano\n"
			"2) Humano cazavampiros\n"
			"3) Vanesa\n"
			"4) Zombi\n"
			"5) Vampiro\n"
			"6) Vampirella\n"
			"7) Nosferatu\n"
			"8) Cruz\n"
			"9) Agua bendita\n"
			"10) Estaca\n"
			"11) Escopeta\n"
			"12) Balas\n";
}

void Menu::agregarDato(){
	int posicionX = -1;
	int posicionY = -1;
	int opcion;
	pedirCoordenadas(posicionX, posicionY);

	if (tablero->esPosicionValida(posicionX, posicionY)){
		mostrarOpcionesAAgregar();
		std::cout << "Ingrese el tipo de elemento que desea agregar: ";
		std::cin >> opcion;
		validarOpcion(opcion, 1, 13);

		if (opcion <= 7)
			crearSer(posicionX, posicionY, opcion);  //Hay que dividirla en los tipos de Ser y asignarle los ids.
		else if (opcion > 7 && opcion <= 12)
			crearElemento(posicionX, posicionY, opcion);
		else
			std::cout << "salir" << std::endl;
		}
	else
		std::cout << "Las coordenadas están fuera del tablero." << std::endl;
}

void Menu::crearSer(int posicionX, int posicionY, int opcion){
	Ser* aux;
	std::string nuevoId = iden.dar_codigo(opcion);
	if (tablero->obtenerCasillero(posicionX, posicionY)->hayPersonaje() || tablero->obtenerCasillero(posicionX, posicionY)->hayElemento())
		std::cout << "Este casillero está ocupado" << std::endl;
	else{
		if (opcion == 1)
			aux = new Humano(posicionX, posicionY, nuevoId);
		else if (opcion == 2)
			aux = new Cazavampiro(posicionX, posicionY, nuevoId);
		else if (opcion == 3)
			aux = new Vanesa(posicionX, posicionY, nuevoId);
		else if (opcion == 4)
			aux = new Zombi(posicionX, posicionY, nuevoId);
		else if (opcion == 5)
			aux = new Vampiro(posicionX, posicionY, nuevoId);
		else if (opcion == 6)
			aux = new Vampirella(posicionX, posicionY, nuevoId);
		else if (opcion == 7)
			aux = new Nosferatu(posicionX, posicionY, nuevoId);

		tablero->agregarDato(posicionX, posicionY, aux);
		diccionarioPersonajes->agregarDato(nuevoId, aux);
		std::cout << nuevoId << std::endl;
		pruebaId++;
	}
}


void Menu::crearElemento(int posicionX, int posicionY, int opcion){
	Elemento* aux;
	std::string nuevoId = to_string(pruebaId);
	if (tablero->obtenerCasillero(posicionX, posicionY)->hayPersonaje() || tablero->obtenerCasillero(posicionX, posicionY)->hayElemento())
		std::cout << "Este casillero está ocupado" << std::endl;
	else{
		if (opcion == 8)
			aux = new Cruz(posicionX, posicionY, nuevoId, 1);
		else if (opcion == 9)
			aux = new Agua(posicionX, posicionY, nuevoId, 20);
		else if (opcion == 10)
			aux = new Estaca(posicionX, posicionY, nuevoId, 1);
		else if (opcion == 11)
			aux = new Escopeta(posicionX, posicionY, nuevoId, 1);
		else if (opcion == 12)
			aux = new Balas(posicionX, posicionY, nuevoId, 20);

		tablero->agregarDato(posicionX, posicionY, aux);
		diccionarioPersonajes->agregarDato(nuevoId, aux);
		std::cout << nuevoId << std::endl;
		pruebaId++;
	}
}

void Menu::validarOpcion(int &opcion, int minimo, int maximo){
	while (opcion < minimo || opcion > maximo){
		std::cout << "Ingrese una opción entre " << minimo << " y " << maximo << ": " << std::endl;
		std::cin >> opcion;
	}
}


void Menu::pedirCoordenadas(int &posicionX, int &posicionY){
	std::cout << "Ingrese la coordenada X: ";
	std::cin >> posicionX;
	std::cout << "Ingrese la coordenada Y: ";
	std::cin >> posicionY;
	posicionX --;
	posicionY --;
}

Menu::~Menu() {
	// TODO Auto-generated destructor stub
}

