#ifndef NODOABB_H_
#define NODOABB_H_

#include <iostream>

template <typename T>

class NodoABB{

private:

	//std::string ID;
	T dato;
	NodoABB* derecho;
	NodoABB* izquierdo;
	NodoABB* padre;

public:

	NodoABB(T item);

	T obtener_dato();

	//std::string obtener_ID();

	void asignar_dato(T item);

	void asignar_derecho(NodoABB<T>* derecho, NodoABB<T>* padre);

	void asignar_izquierdo(NodoABB<T>* izquierdo, NodoABB<T>* padre);

	void asignar_derecho(NodoABB<T>* derecho);

	void asignar_izquierdo(NodoABB<T>* izquierdo);

	void asignar_padre(NodoABB<T>* padre);

	NodoABB<T>* obtener_derecho();

	NodoABB<T>* obtener_izquierdo();

	NodoABB<T>* obtener_padre();

	bool es_hoja();

	bool solo_hijo_derecho();

	bool solo_hijo_izquierdo();
};

template <typename T>
NodoABB<T>::NodoABB(T dato){
	//this->ID = item->obtener_ID();
	this->dato = dato;
	this->derecho = 0;
	this->izquierdo = 0;
	this->padre = 0;
}

template <typename T>
T NodoABB<T>::obtener_dato(){
	return this->dato;
}
/*
template <typename T>
std::string NodoABB<T>::obtener_ID(){
	return this->personaje->obtener_ID();
}
*/
template <typename T>
void NodoABB<T>::asignar_dato(T item){
	this->dato = item;
}

template <typename T>
void NodoABB<T>::asignar_derecho(NodoABB<T>* derecho, NodoABB<T>* padre){
	this->derecho = derecho;
	this->padre = padre;
}

template <typename T>
void NodoABB<T>::asignar_derecho(NodoABB<T>* derecho){
	this->derecho = derecho;
}

template <typename T>
void NodoABB<T>::asignar_izquierdo(NodoABB<T>* izquierdo, NodoABB<T>* padre){
	this->izquierdo = izquierdo;
	this->padre = padre;
}

template <typename T>
void NodoABB<T>::asignar_izquierdo(NodoABB<T>* izquierdo){
	this->izquierdo = izquierdo;
}

template <typename T>
void NodoABB<T>::asignar_padre(NodoABB<T>* padre){
	this->padre = padre;
}

template <typename T>
NodoABB<T>* NodoABB<T>::obtener_derecho(){
	return this->derecho;
}

template <typename T>
NodoABB<T>* NodoABB<T>::obtener_izquierdo(){
	return this->izquierdo;
}

template <typename T>
NodoABB<T>* NodoABB<T>::obtener_padre(){
	return this->padre;
}

template <typename T>
bool NodoABB<T>::es_hoja(){
	return (this->obtener_izquierdo() == 0 && this->obtener_derecho() == 0);
}

template <typename T>
bool NodoABB<T>::solo_hijo_derecho(){
	return (this->obtener_izquierdo() == 0 && this->obtener_derecho() != 0);
}

template <typename T>
bool NodoABB<T>::solo_hijo_izquierdo(){
	return (this->obtener_izquierdo() != 0 && this->obtener_derecho() == 0);
}

#endif /* NODOABB_H_ */
