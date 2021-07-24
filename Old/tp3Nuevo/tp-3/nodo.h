

#ifndef NODO_H_
#define NODO_H_

template <typename Dato>
class Nodo{
private:
	Dato dato;
	Nodo<Dato>* siguiente;
public:
	//PRE:
	//POS: Crea un nuevo nodo con dato = dato y siguiente = nullptr.
	Nodo(Dato dato);

	//PRE:
	//POS: Obtiene el dato contenido en el nodo.
	Dato obtenerDato();

	//PRE:
	//POS: Setea un nodo siguiente al nodo actual.
	void cambiarSiguiente(Nodo<Dato>* nodoSiguiente);

	//PRE:
	//POS: Cambia el dato contenido en el nodo.
	void cambiarDato(Dato nuevoDato);

	//PRE:
	//POS: Obtiene el nodo siguiente o nullptr si este no existe.
	Nodo<Dato>* obtenerSiguiente();

};

template <typename Dato>
Nodo<Dato>::Nodo(Dato dato){
	this -> dato = dato;
	this -> siguiente = nullptr;
}

template <typename Dato>
Dato Nodo<Dato>::obtenerDato(){
	return dato;
}

template <typename Dato>
void Nodo<Dato>::cambiarDato(Dato nuevoDato){
	dato = nuevoDato;
}

template <typename Dato>
void Nodo<Dato>::cambiarSiguiente(Nodo<Dato>* nuevoSiguiente){
	siguiente = nuevoSiguiente;
}

template <typename Dato>
Nodo<Dato>* Nodo<Dato>::obtenerSiguiente(){
	return siguiente;
}


#endif /* NODO_H_ */
