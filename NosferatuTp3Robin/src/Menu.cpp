#include "Menu.h"
#include <iostream>

Menu::Menu() {
	// TODO Auto-generated constructor stub
	this->opcionPrincipal = 0;
	this->opcionSimulacion = 0;
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

void Menu::procesarOpcionSimulacion(){

	switch(opcionSimulacion){

	case BUSCAR_POR_ID_SIMULACION: std::cout << "- BUSCANDO POR ID -(SIMULACION)-" << std::endl;
								   break;

	case MOSTRAR_TABLERO_SIMULACION: std::cout << "- MOSTRARNDO EL TABLERO -(SIMULACION)-" << std::endl;
									 break;

	case MOSTRAR_CANTIDAD_DE_INTEGRANTES_DE_UN_BANDO_SIMULACION: std:: cout << "MOSTRANDO CANTIDAD DE INTEGRANTES X BANDO -(SIMULACION)" << std::endl;
																 break;

	case SELECCIONAR_BANDO_SIMULACION: std::cout << "SELECCIONANDO BANDO -(SIMULACION)-" << std::endl;
									   break;

	case SALIR_SIMULACION: std::cout << "-SALIENDO SIMULACION-" << std::endl;
						   break;

	//default: std:: cout << "Dudo que entre a esta parte de simulacion e.e" << std::endl;
	}
}

void Menu::procesarOpcionPrincipal(){

	switch(opcionPrincipal){

	case AGREGAR_PERSONAJE_U_OBJETO: std::cout << "- AGREGANDO PERSONAJE U OBJETO -" << std::endl;
									 break;

	case ELIMINAR_PERSONAJE_U_OBJETO: std::cout << "- ELIMINANDO PERSONAJE U OBJETO -" << std::endl;
									 break;

	case MOSTRAR_TABLERO: std::cout << "- MOSTRANDO TABLERO -" << std::endl;
						  break;

	case BUSCAR_POR_CUADRANTE: std::cout << "- BUSCAR POR CUADRANTE -" << std::endl;
							   break;

	case BUSCAR_POR_ID: std::cout << "- BUSCANDO POR ID -" << std::endl;
						break;

	case COMENZAR_SIMULACION: std::cout << std::endl;
							  std::cout << "- COMENZANDO SIMULACION - " << std::endl;
							  ingresarOpcionSimulacion();
							  while (opcionSimulacion != SALIR_SIMULACION){
								  procesarOpcionSimulacion();
								  std::cout << std::endl;
								  ingresarOpcionSimulacion();
							  }
							  break;

	case SALIR_MENU_PRINCIPAL: std::cout << "- SALIENDO -" << std::endl;
							   break;

	//default: std::cout << "Dudo que informe esta opcion e.e" << std::endl;
	}
}

Menu::~Menu() {
	// TODO Auto-generated destructor stub
}

