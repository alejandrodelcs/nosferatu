#include <iostream>
#include <cstdlib>
#include <ctime>
#include "tablero.h"
#include "ABB.h"
#include "objeto.h"
#include "estado.h"

#include "Menu.h"


int main() {

    /*
    srand(time(nullptr));

	Tablero* nuevoTablero = new Tablero();

	ABB<string, Objeto*>* diccionarioPersonajes = new ABB<string, Objeto*>();

	Interacciones* interacciones = new Interacciones(nuevoTablero, diccionarioPersonajes);

	//nuevoTablero->mostrarTablero();
//	std::cout << endl;
//	nuevoTablero->mostrarTableroObjetos();
//	nuevoTablero->eliminarDato(3,4);
//	std::cout << endl;
//	nuevoTablero->mostrarTableroObjetos();


	Menu* menu = new Menu(diccionarioPersonajes, nuevoTablero);
	int opcionPrincipal = menu->obtenerOpcionMenuPrincipal();

	while(opcionPrincipal != SALIR_MENU_PRINCIPAL){
		menu->procesarOpcionPrincipal();
		cout << endl;
		menu->ingresarOpcionPrincipal();
		opcionPrincipal = menu->obtenerOpcionMenuPrincipal();
	}
	cout << "Vamo Messi!" << endl;

	delete nuevoTablero;
	delete diccionarioPersonajes;
	delete interacciones;
	delete menu;

    */

    std::ifstream archivo;
    archivo.open("../estado.txt", std::ios::in);

    std::string lineaArchivo;
    std::string nombreItem;
    std::string coordenadaXStr, coordenadaYStr;


    if (archivo.is_open()) {
        std::cout << "el archivo se abrio de manera exitosa" << std::endl;
        Estado estado;
        while (getline(archivo, lineaArchivo)) {
            std::cout<<lineaArchivo<<std::endl;
            estado.leerLineaArchivo(lineaArchivo);
            std::cout<<estado.devolverId()<<std::endl;
        }
    } else {
        std::cerr << "ERROR!...el Archivo" << PATH << "No se abrio" << std::endl;
        exit(1);
    }

    archivo.close();
return 0;
}
