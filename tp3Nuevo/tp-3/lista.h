#include "nodo.h"
#include <iostream>

using namespace std;

const int POSICION_NO_ENCONTRADA = -1;

#ifndef LISTA_H_
#define LISTA_H_

template <typename Dato>
class Lista{
private:
	Nodo<Dato>* primero;
	Nodo<Dato>* actual;
	Nodo<Dato>* ultimo;
	int largo;

	//PRE: 0 < posicion <= largo
	//POS: Devuelve el nodo en la posición pedida.
	Nodo<Dato>* obtenerNodo(int posicion);

public:
	//PRE:
	//POS: Crea una lista vacia.
	Lista();

	//PRE:
	//POS: Devuelve true si la lista esta vacía o false en caso contrario.
	bool estaVacia();

	//PRE:
	//POS: Produce que actual vuelva a apuntar al primero o a nullptr si la lista está vacía.
	void reiniciarActual();

	void agregarDato(Dato dato);

	//PRE: 0 < posicion <= largo
	//POS: Devuelve el dato contenido en el nodo.
	Dato consulta(int posicion);


	void eliminarDato(int posicion);

//	int contador = 0;
//	while (haySiguiente()){
//		contador++;
//		Ser* personajeActual = siguiente();
//		if (personajeActual->obtenerId() == IdMuerto)
//			eliminarDato(i);
//	}

	int obtenerPosicion(Dato dato);

	//PRE:
	//POS: Muestra los datos contenidos en los nodos de la lista. (sirve mejor para cuando los nodos
	//contienen elementos que se pueden mostrar, como string o int).
	void imprimirLista();

	//PRE:
	//POS: Elimina todos los nodos de la lista, liberando así la memoria utilizada.
	~Lista();


	// consulta si hay un elemento siguiente (si el actual no apunta a NULL)
	// PRE:
	// POS: devuelve true si el actual no apunta a NULL, false de lo contrario
	bool haySiguiente();

	// devuelve el siguiente elemento (el elemento que apunta actual)
	// PRE: hay_siguiente tiene que haber devuelto true previamente
	// POS: devuelve el elemento actual y avanza
	Dato siguiente();

	//PRE:
	//POS: Verifica si un dato se encuentra dentro de la lista.
	bool estaEnLaLista(Dato dato);

	int obtenerLargo();
};

template <typename Dato>
Lista<Dato>::Lista(){
	primero = nullptr;
	actual = nullptr;
	ultimo = nullptr;
	largo = 0;
}


template <typename Dato>
bool Lista<Dato>::estaVacia(){
	return (largo == 0);
}

template <typename Dato>
Nodo<Dato>* Lista<Dato>::obtenerNodo(int posicion){
	Nodo<Dato>* aux = primero;
	for (int i = 1; i < posicion; i++)
		aux = aux -> obtenerSiguiente();
	return aux;
}

template <typename Dato>
void Lista<Dato>::reiniciarActual(){
	actual = primero;
}


template < typename Dato >
void Lista<Dato>::agregarDato(Dato dato) {
    Nodo<Dato>* nuevoNodo = new Nodo<Dato>(dato);
    if(primero == nullptr){
        primero = nuevoNodo;
        ultimo = primero;
    } else {
        ultimo -> cambiarSiguiente(nuevoNodo);
        ultimo = nuevoNodo;
    }
    largo++;
}

template <typename Dato>
Dato Lista<Dato>::consulta(int posicion){
	Nodo<Dato>* nodo = obtenerNodo(posicion);
	return nodo -> obtenerDato();
}

template <typename Dato>
int Lista<Dato>::obtenerPosicion(Dato dato){
    bool elementoEncontrado = false;
    int i = 0;
    Nodo<Dato>* auxiliar = primero;

    while(!elementoEncontrado && i < largo){
        if(auxiliar->obtenerDato() == dato){
            elementoEncontrado = true;
        }
        i++;
        auxiliar = auxiliar -> obtenerSiguiente();
    }

    if(!elementoEncontrado){
        return POSICION_NO_ENCONTRADA;
    }
    return i - 1;
}

template <typename Dato>
void Lista<Dato>::imprimirLista(){
	reiniciarActual();
	while (haySiguiente())
		cout << "->" << siguiente();
	cout << endl;
}

template<typename Dato>
Lista<Dato>::~Lista() {
    Nodo<Dato>* siguiente;
    while(primero != nullptr){
        siguiente = primero -> obtenerSiguiente();
        delete primero;
        primero = siguiente;
    }
}

template <typename Dato>
bool Lista<Dato>::haySiguiente(){
	return (actual != nullptr);
}

template <typename Dato>
Dato Lista<Dato>::siguiente(){
	Nodo<Dato>* aux = actual;
	actual = actual -> obtenerSiguiente();
	return aux -> obtenerDato();
}

template <typename Dato>
bool Lista<Dato>::estaEnLaLista(Dato dato) {
    bool encontrado = false;
    reiniciarActual();
    while (haySiguiente() && ! encontrado) {
        if (siguiente() == dato)
            encontrado = true;
    }
    return encontrado;
}

template <typename Dato>
int Lista<Dato>::obtenerLargo(){
	return largo;
}


template <typename Dato>
void Lista<Dato>::eliminarDato(int posicion){
	if (posicion == 1){
		Nodo<Dato>* nodoABorrar = primero;
		primero = nodoABorrar -> obtenerSiguiente();
		delete nodoABorrar;
	}
	else{
		Nodo<Dato>* anterior = obtenerNodo(posicion - 1);
		Nodo<Dato>* nodoABorrar = anterior -> obtenerSiguiente();
		anterior -> cambiarSiguiente(nodoABorrar -> obtenerSiguiente());
		delete nodoABorrar;
	}
	reiniciarActual();
	largo--;
}


#endif /* LISTA_H_ */
