#include <iostream>
#include <string>

using namespace std;

#ifndef NODOAB_H_
#define NODOAB_H_

//typedef string Clave;  //cambiar el valor en el constructor
//typedef string Valor;  //cambiar el valor en el constructor

template <typename Clave, typename Valor>
class NodoAB{
private:
	Clave clave;
	Valor valor;
	NodoAB* izquierdo;
	NodoAB* derecho;
	NodoAB* padre;

public:
	NodoAB();
	void asignarClave(Clave clave);
	void asignarValor(Valor valor);
	void asignarIzquierdo(NodoAB *izquierdo);
	void asignarDerecho(NodoAB *derecho);
	void asignarPadre(NodoAB *padre);

	bool tieneHijoDerecho();
	bool tieneHijoIzquierdo();
	bool tieneDosHijos();
	bool esHoja();

	Clave obtenerClave();
	Valor obtenerValor();
	NodoAB* obtenerIzquierdo();
	NodoAB* obtenerDerecho();
	NodoAB* obtenerPadre();

	//~NodoAB();
};


template <typename Clave, typename Valor>
NodoAB<Clave,Valor>::NodoAB(){
	clave = " ";
	valor = nullptr;
	izquierdo = nullptr;
	derecho = nullptr;
	padre = nullptr;
}


template <typename Clave, typename Valor>
void NodoAB<Clave,Valor>::asignarClave(Clave clave){
	this->clave = clave;
}


template <typename Clave, typename Valor>
void NodoAB<Clave,Valor>::asignarValor(Valor valor){
	this->valor = valor;
}


template <typename Clave, typename Valor>
void NodoAB<Clave,Valor>::asignarIzquierdo(NodoAB *izquierdo){
	this->izquierdo = izquierdo;
}


template <typename Clave, typename Valor>
void NodoAB<Clave,Valor>::asignarDerecho(NodoAB *derecho){
	this->derecho = derecho;
}


template <typename Clave, typename Valor>
void NodoAB<Clave,Valor>::asignarPadre(NodoAB *padre){
	this->padre = padre;
}


template <typename Clave, typename Valor>
Clave NodoAB<Clave,Valor>::obtenerClave(){
	return this->clave;
}


template <typename Clave, typename Valor>
Valor NodoAB<Clave,Valor>::obtenerValor(){
	return this->valor;
}


template <typename Clave, typename Valor>
NodoAB<Clave, Valor>* NodoAB<Clave,Valor>::obtenerIzquierdo(){
	return this->izquierdo;
}


template <typename Clave, typename Valor>
NodoAB<Clave, Valor>* NodoAB<Clave,Valor>::obtenerDerecho(){
	return this->derecho;
}


template <typename Clave, typename Valor>
NodoAB<Clave, Valor>* NodoAB<Clave,Valor>::obtenerPadre(){
	return this->padre;
}


template <typename Clave, typename Valor>
bool NodoAB<Clave,Valor>::tieneDosHijos(){
	if (obtenerIzquierdo() != nullptr && obtenerDerecho() != nullptr)
		return true;
	return false;
}


template <typename Clave, typename Valor>
bool NodoAB<Clave,Valor>::tieneHijoDerecho(){
	if (obtenerDerecho() != nullptr && obtenerIzquierdo() == nullptr)
		return true;
	return false;
}


template <typename Clave, typename Valor>
bool NodoAB<Clave,Valor>::tieneHijoIzquierdo(){
	if (obtenerIzquierdo() != nullptr && obtenerDerecho() == nullptr)
		return true;
	return false;
}


template <typename Clave, typename Valor>
bool NodoAB<Clave,Valor>::esHoja(){
	if (obtenerIzquierdo() == nullptr && obtenerDerecho() == nullptr)
		return true;
	return false;
}

//template <typename Clave, typename Valor>
//NodoAB<Clave,Valor>::~NodoAB(){
//	if (valor != nullptr)
//		delete valor;
//}

#endif /* NODOAB_H_ */
