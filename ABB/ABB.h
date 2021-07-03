#ifndef ABB_H_
#define ABB_H_

#include "NodoABB.h"
#include <iostream>

template <typename T>

class ABB{

private:

	NodoABB<T>* raiz;

public:

	ABB();

	//T obtener_item(std::string clave);

	void insertar(T dato);

	void imprimir_en_orden();

	bool buscar(T dato);

	T encontrar_minimo();

	T encontrar_maximo();

	T sucesor(T dato);

	T predecesor(T dato);

	void borrar_dato(T dato);

	NodoABB<T>* obtener_raiz();

	bool vacio();

	void borrar_todo();

	~ABB();

private:

	NodoABB<T>* insertar(NodoABB<T>* nodo, T dato);

	void imprimir_en_orden(NodoABB<T>* nodo);

	NodoABB<T>* buscar(NodoABB<T>* nodo, T dato);

	T encontrar_minimo(NodoABB<T>* nodo);

	T encontrar_maximo(NodoABB<T>* nodo);

	T sucesor(NodoABB<T>* nodo);

	T predecesor(NodoABB<T>* nodo);

	NodoABB<T>* borrar_dato(NodoABB<T>* nodo, T dato);

	void borrar_todo(NodoABB<T>* nodo);
};


template <typename T>
ABB<T>::ABB(){
	this->raiz = 0;
}

template <typename T>
ABB<T>::~ABB<T>(){
	borrar_todo();
}

template <typename T>
void ABB<T>::imprimir_en_orden(){
	this->imprimir_en_orden(this->raiz);
}

template <typename T>
void ABB<T>::insertar(T dato){
	this->raiz = insertar(this->raiz, dato);
}

template <typename T>
bool ABB<T>::buscar(T dato){
	NodoABB<T>* resulutado = buscar(this->raiz, dato);
	return (resulutado != 0);
}

template <typename T>
T ABB<T>::encontrar_minimo(){
	return encontrar_minimo(this->raiz);
}

template <typename T>
T ABB<T>::encontrar_maximo(){
	return encontrar_maximo(this->raiz);
}

template <typename T>
T ABB<T>::sucesor(T dato){
	NodoABB<T>* nodo = this->buscar(this->raiz, dato);
	if (nodo == 0)
		return -1;
	else
		return sucesor(nodo);
}

template <typename T>
T ABB<T>::predecesor(T dato){
	NodoABB<T>* nodo = this->buscar(this->raiz, dato);

	if (nodo == 0)
		return -1;
	else
		return predecesor(nodo);
}

template <typename T>
NodoABB<T>* ABB<T>::borrar_dato(NodoABB<T>* nodo, T dato){
	if (nodo == 0)
		return 0;

	if(nodo->obtener_dato() == dato){
		if(nodo->es_hoja()){
			delete nodo;
			return 0;
		}
		else
			if (nodo->solo_hijo_derecho()){
				nodo->obtener_derecho()->asignar_padre(nodo->obtener_padre());
				NodoABB<T>* aux = nodo;
				nodo = nodo->obtener_derecho();
				delete aux;
			}
			else
				if (nodo->solo_hijo_izquierdo()){
					nodo->obtener_izquierdo()->asignar_padre(nodo->obtener_padre());
					NodoABB<T>* aux = nodo;
					nodo = nodo->obtener_izquierdo();
					delete aux;
				}
				else{
					T dato_sucesor = this->sucesor(dato);
					nodo->asignar_dato(dato_sucesor);
					nodo->asignar_derecho(borrar_dato(nodo->obtener_derecho(), dato_sucesor));
				}
	}
	else
		if (nodo->obtener_dato() < dato)
			nodo->asignar_derecho(borrar_dato(nodo->obtener_derecho(), dato));
		else
			nodo->asignar_izquierdo(borrar_dato(nodo->obtener_izquierdo(), dato));

	return nodo;
}


template <typename T>
NodoABB<T>* ABB<T>::obtener_raiz(){
	return this->raiz;
}

template <typename T>
bool ABB<T>::vacio(){
	return this->raiz == 0;
}

template <typename T>
T ABB<T>::predecesor(NodoABB<T>* nodo){
	if (nodo->obtener_izquierdo() != 0){
		return encontrar_maximo(nodo->obtener_izquierdo());
	}

	NodoABB<T>* sucesor = 0;
	NodoABB<T>* ancestro = this->raiz;
	while (ancestro != nodo){
		if (nodo->obtener_dato() > ancestro->obtener_dato()){
			sucesor = ancestro;
			ancestro = ancestro->obtener_izquierdo();
		}
		else
			ancestro = ancestro->obtener_derecho();
	}
	return sucesor->obtener_dato();
}

template <typename T>
T ABB<T>::sucesor(NodoABB<T>* nodo){
	if (nodo->obtener_derecho() != 0){
		return encontrar_minimo(nodo->obtener_derecho());
	}
	NodoABB<T>* sucesor = 0;
	NodoABB<T>* ancestro = this->raiz;
	while (ancestro != nodo){
		if (nodo->obtener_dato() < ancestro->obtener_dato()){
			sucesor = ancestro;
			ancestro = ancestro->obtener_izquierdo();
		}
		else
			ancestro = ancestro->obtener_derecho();
	}
	return sucesor->obtener_dato();
}

template <typename T>
T ABB<T>::encontrar_minimo(NodoABB<T>* nodo){
	if (nodo == 0)
		return -1;

	else if (nodo->obtener_izquierdo() == 0)
		return nodo->obtener_dato();

	else
		return encontrar_minimo(nodo->obtener_izquierdo());
}

template <typename T>
T ABB<T>::encontrar_maximo(NodoABB<T>* nodo){
	if (nodo == 0)
		return -1;

	else if (nodo->obtener_derecho() == 0)
		return nodo->obtener_dato();

	else
		return encontrar_maximo(nodo->obtener_derecho());
}


template <typename T>
NodoABB<T>* ABB<T>::insertar(NodoABB<T>* nodo, T dato){

	if(nodo == 0){
		nodo = new NodoABB<T>(dato);
	}
	else if (dato > nodo->obtener_dato()){
		nodo->asignar_derecho(insertar(nodo->obtener_derecho(), dato), nodo);
	}
	else{
		nodo->asignar_izquierdo(insertar(nodo->obtener_izquierdo(), dato), nodo);;
	}
	return nodo;
}

template <typename T>
void ABB<T>::imprimir_en_orden(NodoABB<T>* nodo){
	if (nodo != 0){
		imprimir_en_orden(nodo->obtener_izquierdo());
		std::cout << nodo->obtener_dato() << " ";
		imprimir_en_orden(nodo->obtener_derecho());
	}
}

template <typename T>
NodoABB<T>* ABB<T>::buscar(NodoABB<T>* nodo, T dato){
	if (nodo == 0 || nodo->obtener_dato() == dato)
		return nodo;

	if (dato > nodo->obtener_dato())
		return buscar(nodo->obtener_derecho(), dato);

	return buscar(nodo->obtener_izquierdo(), dato);
}

template<typename T>
void ABB<T>::borrar_dato(T dato){
	this->raiz = borrar_dato(this->raiz, dato);
}

template<typename T>
void ABB<T>::borrar_todo(){
	this->borrar_todo(this->raiz);
}

template<typename T>
void ABB<T>::borrar_todo(NodoABB<T>* nodo){
	if (nodo == 0)
		return;
	this->borrar_todo(nodo->obtener_izquierdo());
	this->borrar_todo(nodo->obtener_derecho());
	delete nodo;
}


#endif /* ABB_H_ */
