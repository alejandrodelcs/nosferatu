#include <iostream>
#include "Menu.h"
#include "constantes.h"

Menu::Menu() {
	// TODO Auto-generated constructor stub
	opcion = 0;
}

void Menu::mostrar_menu(){
	std::cout << "-----MENU NOSFERATU-----" << std::endl;
	std::cout << "1.Mostrar tablero" << std::endl;
	std::cout << "2.Mostrar estadisticas" << std::endl;
	std::cout << "3.Buscar por cuadrante" << std::endl;
	std::cout << "4.Dar de alta un elemento" << std::endl;
	std::cout << "5.Dar de baja un elemento" << std::endl;
	std::cout << "6.Informacion sobre un elemento en particular" << std::endl;
	std::cout << "7.Salir" << std::endl;
}

void Menu::ingresar_opcion(){
	mostrar_menu();
	std::cout << "Ingrese una opcion: ";
	std::cin >> opcion;
	validar_opcion(opcion);
}

void Menu::validar_opcion(int & opcion){
	while (opcion < MOSTRAR_TABLERO || opcion > SALIR){
		std::cout << "Opcion incorrecta, reingrese: ";
		std::cin >> opcion;
	}
}

int Menu::obtener_opcion_menu(){
	return opcion;
}

void Menu::procesar_opcion(MatrizItems* & matriz){
	Items* item;
	int posX = 0;
	int posY = 0;
	Contadores* contador;
	int cuadrante = 0;
	int objeto_buscado = 0;

	switch(opcion){

		case MOSTRAR_TABLERO: std::cout << std::endl;
						      matriz->dibujar_estado_tablero();
							  break;

		case MOSTRAR_CUADRO_RESUMEN: std::cout << "=============*CUADRO RESUMEN*=============" << std::endl;
									 matriz->mostrar_cuadro_estadistico(contador);
									 break;

		case BUSCAR_POR_CUADRANTE: std::cout << "======BUSQUEDA POR CUADRANTE======" << std::endl;
								   matriz->buscar_por_cuadrante(cuadrante, objeto_buscado);
									//matriz->mostrar_contenido_matriz();
								   break;

		case DAR_ALTA: std::cout << "============*DAR ALTA*============" << std::endl;
					   matriz->dibujar_estado_tablero();
					   matriz->dar_alta_elemento_en_matriz(item, posX, posY);
					   matriz->dibujar_estado_tablero();
					   break;

		case DAR_BAJA: std::cout << "============*DAR BAJA*============" << std::endl;
									 matriz->dibujar_estado_tablero();
									 matriz->dar_baja_elemento_en_matriz(posX, posY);
									 matriz->dibujar_estado_tablero();
									 break;

		case INFORMAR_ELEMENTO: std::cout << "Informar sobre elemento en una determinada posicion" << std::endl;
								matriz->informar_sobre_un_elemento_en_particular(posX, posY);
								break;

		case SALIR: std::cout << std::endl; break;
		default : std::cout << "Dudo que salga esta opcion e.e" << std::endl;
	}
}

Menu::~Menu() {
	// TODO Auto-generated destructor stub
}

