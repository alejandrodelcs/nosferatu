#include <iostream>
#include "MatrizItems.h"
#include "Menu.h"

#include "Items.h"
#include "ItemBala.h"

using namespace std;

int main(){


	Menu menu;
	MatrizItems* matriz = new MatrizItems;

	matriz = matriz->cargar_matriz();

	menu.ingresar_opcion();
	int opcion = menu.obtener_opcion_menu();

	while (opcion != SALIR){
		menu.procesar_opcion(matriz);
		cout << endl;
		menu.ingresar_opcion();
		opcion = menu.obtener_opcion_menu();
	}

	cout << "Vamo' Messi! :)" << endl;

	//matriz->liberar_personajes();
	matriz->~MatrizItems();
	delete matriz;


	return 0;
}



