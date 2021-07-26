#include "NodoABB.h"

#ifndef ARBOL_BINARIO_H_
#define ARBOL_BINARIO_H_

template <typename Clave, typename Valor>
class ABB{
private:
    NodoAB<Clave, Valor>* raiz;
    NodoAB<Clave, Valor>* actual;

    //PRE:
    //POS: Agrega un nuevo nodo al arbol diccionario.
    void agregarNodo(NodoAB<Clave, Valor>* nuevo_nodo);

    //PRE:
    //POS: Imprime el arbol diccionario en orden (claves ascendientes).
    void imprimirArbol(NodoAB<Clave, Valor>* raiz);

    //PRE: La clave se encuentra en el diccionario.
    //POS: Busca un clave en el diccionario y devuelve su valor.
    NodoAB<Clave, Valor>* buscar(Clave clave, NodoAB<Clave, Valor>* raiz);

    //PRE:
    //POS: Devuelve true si la clave se encuentra en el diccionario, false en caso contrario.
    bool esta(Clave clave, NodoAB<Clave, Valor>* nodo);

    void eliminarNodo(NodoAB<Clave, Valor>* nodo_eliminar);
    void eliminarHoja(NodoAB<Clave, Valor>* nodo_eliminar);
    void eliminarNodoConHijoIzquierdo(NodoAB<Clave, Valor>* nodo_eliminar);
    void eliminarNodoConHijoDerecho(NodoAB<Clave, Valor>* nodo_eliminar);
    void eliminarNodoConDosHijos(NodoAB<Clave, Valor>* nodo_eliminar);
    void eliminarRaiz();

    //PRE:
    //POS: Busca el hijo del nodo, que se encuentra más a la derecha.
    NodoAB<Clave, Valor>* encontrarPredecesor(NodoAB<Clave, Valor>* nodo);


public:

    //PRE:
    //POS: Crea un arbol binario diccionario
    ABB();

    //PRE:
    //POS: Devuelve true si el diccionario está vacío, false en caso contrario.
    bool estaVacio();

    //PRE:
    //POS: Máscara a la cuál se le pasa la clave y el valor y crea un nuevo nodo que luego es
    //     agregado al diccionario mediante la función agregarDato(Nodo).
    void agregarDato(Clave clave, Valor valor);

    //PRE:
    //POS: Máscara que llama a la función imprimir árbol, que imprime el diccionario en orden de claves
    //     ascendentes.
    void imprimirArbol();

    //PRE: La clave se encuentra en el diccionario
    //POS: Máscara que llama a la función buscar().
    Valor buscar(Clave clave);

    //PRE:
    //POS: Máscara que llama a la función esta()
    bool esta(Clave clave);

    //PRE: La clave está en el diccionario
    //POS: Máscara que llama a la función eliminarNodo().
    void eliminarNodo(Clave clave);

    //MÉTODOS PARA VERIFICAR EL CORRECTO ARMADO DEL ARBOL
    //void imprimirPadre(Clave clave);
    //void imprimirIzquierdo(Clave clave);
    //void imprimirDerecho(Clave clave);

    ~ABB();
};


template <typename Clave, typename Valor>
ABB<Clave,Valor>::ABB(){
    raiz = nullptr;
    actual = nullptr;
}


template <typename Clave, typename Valor>
bool ABB<Clave,Valor>::estaVacio(){
    if (raiz == nullptr)
        return true;
    return false;
}


template <typename Clave, typename Valor>
void ABB<Clave,Valor>::agregarDato(Clave clave, Valor valor){
    NodoAB<Clave, Valor>* nuevo_nodo = new NodoAB<Clave, Valor>;
    nuevo_nodo->asignarClave(clave);
    nuevo_nodo->asignarValor(valor);
    agregarNodo(nuevo_nodo);
}


template <typename Clave, typename Valor>
void ABB<Clave,Valor>::agregarNodo(NodoAB<Clave, Valor>* nuevo_nodo){
    NodoAB<Clave, Valor>* aux = raiz;
    actual = raiz;
    while(aux != nullptr){
        actual = aux;
        if(nuevo_nodo->obtenerClave() < aux->obtenerClave()){
            aux = aux->obtenerIzquierdo();
        }
        else{
            aux = aux->obtenerDerecho();
        }
    }
    if (raiz == nullptr){
        raiz = nuevo_nodo;
    }
    else{
        if(nuevo_nodo->obtenerClave() < actual->obtenerClave()){
            actual->asignarIzquierdo(nuevo_nodo);
            nuevo_nodo->asignarPadre(actual);
        }
        else{
            actual->asignarDerecho(nuevo_nodo);
            nuevo_nodo->asignarPadre(actual);
        }
    }
}



template <typename Clave, typename Valor>
ABB<Clave,Valor>::~ABB(){
    while (! estaVacio())
        eliminarNodo(raiz);
}


template <typename Clave, typename Valor>
void ABB<Clave,Valor>::imprimirArbol(NodoAB<Clave, Valor>* raiz){
    if (raiz != nullptr){
        imprimirArbol(raiz->obtenerIzquierdo());
        cout << raiz->obtenerClave();
        cout << ":";
        cout << raiz->obtenerValor() << endl;
        imprimirArbol(raiz->obtenerDerecho());
    }
}


template <typename Clave, typename Valor>
void ABB<Clave,Valor>::imprimirArbol(){
    imprimirArbol(raiz);
}


template <typename Clave, typename Valor>
Valor ABB<Clave,Valor>::buscar(Clave clave){
    NodoAB<Clave, Valor>* nodo = buscar(clave, raiz);
    return nodo->obtenerValor();

}

template <typename Clave, typename Valor>
bool ABB<Clave,Valor>::esta(Clave clave, NodoAB<Clave,Valor>* nodo){
    if (nodo == nullptr)
        return false;
    else if (clave == nodo->obtenerClave())
        return true;
    else if (clave < nodo->obtenerClave())
        return esta(clave, nodo->obtenerIzquierdo());
    else
        return esta(clave, nodo->obtenerDerecho());
}


template <typename Clave, typename Valor>
bool ABB<Clave,Valor>::esta(Clave clave){  //cambiar nombre ExisteLaClave
    return esta(clave, raiz);
}


template <typename Clave, typename Valor>
NodoAB<Clave, Valor>* ABB<Clave,Valor>::buscar(Clave clave, NodoAB<Clave, Valor>* raiz){
    if (raiz == nullptr || clave == raiz->obtenerClave()) //Cambiar la máscara
        return raiz;
    if(clave > raiz->obtenerClave()){
        return buscar(clave, raiz->obtenerDerecho());
    }
    return buscar(clave, raiz->obtenerIzquierdo());
}


template <typename Clave, typename Valor>
void ABB<Clave,Valor>::eliminarNodo(Clave clave){
    NodoAB<Clave, Valor>* nodo_eliminar = buscar(clave, raiz);
    eliminarNodo(nodo_eliminar);
}


template <typename Clave, typename Valor>
void ABB<Clave,Valor>::eliminarNodo(NodoAB<Clave, Valor>* nodo_eliminar){
    //si el nodo es la raiz (caso particular)
    if (nodo_eliminar == raiz){
        eliminarRaiz();
    }
    else if (nodo_eliminar->esHoja()){
        eliminarHoja(nodo_eliminar);
    }
    else if (nodo_eliminar->tieneHijoIzquierdo()){
        eliminarNodoConHijoIzquierdo(nodo_eliminar);
    }
    else if (nodo_eliminar->tieneHijoDerecho()){
        eliminarNodoConHijoDerecho(nodo_eliminar);
    }
    else if (nodo_eliminar->tieneDosHijos()){
        eliminarNodoConDosHijos(nodo_eliminar);
    }
}


template <typename Clave, typename Valor>
void ABB<Clave,Valor>::eliminarHoja(NodoAB<Clave, Valor>* nodo_eliminar){
    NodoAB<Clave, Valor>* padre = nodo_eliminar->obtenerPadre();
    if (padre->obtenerIzquierdo() == nodo_eliminar){
        padre->asignarIzquierdo(nullptr);
    }
    else{
        padre->asignarDerecho(nullptr);
    }
    delete nodo_eliminar;
}


template <typename Clave, typename Valor>
void ABB<Clave,Valor>::eliminarNodoConHijoIzquierdo(NodoAB<Clave, Valor>* nodo_eliminar){
    NodoAB<Clave, Valor>* padre = nodo_eliminar->obtenerPadre();
    NodoAB<Clave, Valor>* aux = nodo_eliminar;
    if (padre->obtenerIzquierdo() == nodo_eliminar){
        padre->asignarIzquierdo(nodo_eliminar->obtenerIzquierdo());
    }
    else{
        padre->asignarDerecho(nodo_eliminar->obtenerIzquierdo());
    }
    nodo_eliminar->obtenerIzquierdo()->asignarPadre(padre);
    delete aux;
}


template <typename Clave, typename Valor>
void ABB<Clave,Valor>::eliminarNodoConHijoDerecho(NodoAB<Clave, Valor>* nodo_eliminar){
    NodoAB<Clave, Valor>* padre = nodo_eliminar->obtenerPadre();
    NodoAB<Clave, Valor>* aux = nodo_eliminar;
    if (padre->obtenerIzquierdo() == nodo_eliminar){
        padre->asignarIzquierdo(nodo_eliminar->obtenerDerecho());
    }
    else{
        padre->asignarDerecho(nodo_eliminar->obtenerDerecho());
    }
    nodo_eliminar->obtenerDerecho()->asignarPadre(padre);
    delete aux;
}


template <typename Clave, typename Valor>
void ABB<Clave,Valor>::eliminarNodoConDosHijos(NodoAB<Clave, Valor>* nodo_eliminar){
    NodoAB<Clave, Valor>* predecesor = encontrarPredecesor(nodo_eliminar->obtenerIzquierdo());
    nodo_eliminar->asignarClave(predecesor->obtenerClave());
    nodo_eliminar->asignarValor(predecesor->obtenerValor());
    eliminarNodo(predecesor);
}


template <typename Clave, typename Valor>
NodoAB<Clave, Valor>* ABB<Clave,Valor>::encontrarPredecesor(NodoAB<Clave, Valor>* nodo){
    if (nodo->obtenerDerecho() == nullptr)
        return nodo;
    else{
        return encontrarPredecesor(nodo->obtenerDerecho());
    }
}

template <typename Clave, typename Valor>
void ABB<Clave,Valor>::eliminarRaiz(){
    if (raiz->esHoja()){
        NodoAB<Clave, Valor>* aux = raiz;
        raiz = nullptr;
        delete aux;
    }
    else if (raiz->tieneHijoIzquierdo()){
        raiz->asignarClave(raiz->obtenerIzquierdo()->obtenerClave());
        raiz->asignarValor(raiz->obtenerIzquierdo()->obtenerValor());
        eliminarNodo(raiz->obtenerIzquierdo());
    }
    else if (raiz->tieneHijoDerecho()){
        raiz->asignarClave(raiz->obtenerDerecho()->obtenerClave());
        raiz->asignarValor(raiz->obtenerDerecho()->obtenerValor());
        eliminarNodo(raiz->obtenerDerecho());
    }
    else if (raiz->tieneDosHijos()){
        NodoAB<Clave, Valor>* predecesor = encontrarPredecesor(raiz->obtenerIzquierdo());
        raiz->asignarClave(predecesor->obtenerClave());
        raiz->asignarValor(predecesor->obtenerValor());
        eliminarNodo(predecesor);
    }
}


//template <typename Clave, typename Valor>
//void ABB<Clave,Valor>::imprimirPadre(Clave clave){
//    NodoAB<Clave, Valor>* nodo = buscar(clave, raiz);
//    Clave clave_padre = nodo->obtenerPadre()->obtenerClave();
//    cout << clave_padre << endl;
//}
//
//
//template <typename Clave, typename Valor>
//void ABB<Clave,Valor>::imprimirIzquierdo(Clave clave){
//    NodoAB<Clave, Valor>* nodo = buscar(clave, raiz);
//    Clave clave_izquierdo = nodo->obtenerIzquierdo()->obtenerClave();
//    cout << clave_izquierdo << endl;
//}
//
//
//template <typename Clave, typename Valor>
//void ABB<Clave,Valor>::imprimirDerecho(Clave clave){
//    NodoAB<Clave, Valor>* nodo = buscar(clave, raiz);
//    Clave clave_derecho = nodo->obtenerDerecho()->obtenerClave();
//    cout << clave_derecho << endl;
//}





#endif /* ARBOL_BINARIO_H_ */
