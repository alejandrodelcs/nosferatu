#include <iostream>
using namespace std;

#include "ABB.h"

int main (){

	ABB<int>* arbol = new ABB<int>;

	arbol->insertar(10);
	arbol->insertar(5);
	arbol->insertar(7);
	arbol->insertar(12);
	arbol->insertar(15);

	arbol->imprimir_en_orden();
	cout << endl;

	cout << arbol->buscar(12) << endl;
	cout << arbol->buscar(17) << endl;


	arbol->borrar_dato(7);

	arbol->imprimir_en_orden();

	delete arbol;


	return 0;
}


