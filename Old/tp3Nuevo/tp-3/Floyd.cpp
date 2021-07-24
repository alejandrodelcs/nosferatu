#include "Floyd.h"
const int INFINITO = 99999999;

int ** Floyd::crearMatrizCaminos(){

    int ** caminos = new int*[cantidadVertices];
    for(int i = 0; i < cantidadVertices; i++){
        caminos[i] = new int[cantidadVertices];
    }

    for(int i = 0; i < cantidadVertices; i++){
        for(int j = 0; j < cantidadVertices; j++) {
            caminos[i][j] = j;
        }
    }

    return caminos;
}

int ** Floyd::crearMatrizCostos(int ** matrizAdyacencia){

    int ** costos = new int*[cantidadVertices];
    for(int i = 0; i < cantidadVertices; i++){
        costos[i] = new int[cantidadVertices];
    }

    for(int i = 0; i < cantidadVertices; i++){
        for(int j = 0; j < cantidadVertices; j++){
            costos[i][j] = matrizAdyacencia[i][j];
        }
    }
    return costos;
}

//void Floyd::mostrarMatrices(){
//    cout << "Matriz de costos:      ||           Matriz de caminos:" << endl;
//    string filaCostos = "";
//    string filaCaminos = "";
//    for(int i = 0; i < cantidadVertices; i++){
//        for(int j = 0; j < cantidadVertices * 2; j++) {
//            if(j == cantidadVertices * 2 - 1){
//                filaCostos += "            ||           ";
//                filaCaminos += "\n";
//            } else if(j % 2 == 0){
//                if(matrizCostos[i][j/2] == INFINITO){
//                    filaCostos += "∞";
//                } else {
//                    filaCostos += to_string(matrizCostos[i][j/2]);
//                }
//
//                if(matrizCaminos[i][j/2] == POSICION_NO_ENCONTRADA){
//                    filaCaminos += "-";
//                } else {
//                    filaCaminos += vertices ->consulta(matrizCaminos[i][j/2] + 1);
//                }
//            } else{
//                filaCaminos += "|";
//                filaCostos += "|";
//            }
//        }
//        cout << filaCostos << filaCaminos;
//        filaCostos = "";
//        filaCaminos = "";
//    }
//    cout << endl;
//}

void Floyd::calcularMatrices(int ** matrizAdyacencia) {
;
    matrizCostos = crearMatrizCostos(matrizAdyacencia);
    matrizCaminos = crearMatrizCaminos();

    int costo;

    for (int verticeIntermedio = 0; verticeIntermedio < cantidadVertices; verticeIntermedio++){

    	for (int origen = 0; origen < cantidadVertices; origen++){

    		for(int destino = 0; destino < cantidadVertices; destino++){

    			costo = matrizCostos[origen][verticeIntermedio] + matrizCostos[verticeIntermedio][destino];

    			if (matrizCostos[origen][destino] > costo){
    				matrizCostos[origen][destino] = costo;
    				matrizCaminos[origen][destino] = matrizCaminos[origen][verticeIntermedio];
    			}

    			else if (matrizCostos[origen][destino] == INFINITO){
    				matrizCaminos[origen][destino] = POSICION_NO_ENCONTRADA;
    			}
    		}
    	}
    	//cout << "Iteracion numero: " << verticeIntermedio << endl;
    }
    //mostrarMatrices();
}

void Floyd::caminoMinimo(int origen, int destino, Tablero* tablero, Lista<Coordenadas*>* movimientos, int &energiaNecesaria) {
	int posicionOrigen[2];
	int posicionDestino[2];
	obtenerPosicionInversa(tablero, origen, posicionOrigen);
	obtenerPosicionInversa(tablero, destino, posicionDestino);

    if(matrizCaminos[origen][destino] == POSICION_NO_ENCONTRADA){
        cout << "No hay un camino que conecte el casillero (" <<  posicionOrigen[0] << "," << posicionOrigen[1] << ") con (" << posicionDestino[0] << "," << posicionDestino[1] << ")"; //vertices->consulta(destino + 1);
    }else{
    	energiaNecesaria = matrizCostos[origen][destino];
        cout << "El camino minimo que une (" <<  posicionOrigen[0] << "," << posicionOrigen[1] << ") con (" << posicionDestino[0] << "," << posicionDestino[1] << ")";
        cout << " tiene un costo de: " << matrizCostos[origen][destino] << " y es el siguiente: ";
        cout << "(" << posicionOrigen[0] << "," << posicionOrigen[1] << ")";
        do{
            origen = matrizCaminos[origen][destino];
            Coordenadas* nuevaCoordenada = new Coordenadas(posicionOrigen[0], posicionOrigen[1]);
            movimientos->agregarDato(nuevaCoordenada);
            obtenerPosicionInversa(tablero, origen, posicionOrigen);
            cout << " -> " << "(" << posicionOrigen[0] << "," << posicionOrigen[1] << ")";
        }while(origen != destino);
        Coordenadas* nuevaCoordenada = new Coordenadas(posicionOrigen[0], posicionOrigen[1]);
        movimientos->agregarDato(nuevaCoordenada);
    }
    cout << endl;

}

void Floyd::liberarMatrices() {
    if(matrizCostos != nullptr && matrizCaminos != nullptr){
        for(int i = 0; i < cantidadVertices; i++){
            delete[] matrizCostos[i];
            delete[] matrizCaminos[i];
        }
        delete[] matrizCostos;
        delete[] matrizCaminos;

        matrizCostos = nullptr;
        matrizCaminos = nullptr;
    }
}

Floyd::~Floyd() {
    liberarMatrices();
}

Floyd::Floyd(int cantidadVertices) {
    this -> matrizCaminos = nullptr;
    this -> matrizCostos = nullptr;
    this -> cantidadVertices = cantidadVertices;
}

void Floyd::obtenerPosicionInversa(Tablero* tablero, int posicion, int posicionFinal[]){
	int posicionX;
	int posicionY;
	posicionX = posicion % tablero->obtenerCantidadColumnas();
	posicionY = posicion / tablero->obtenerCantidadColumnas();
	posicionFinal[0] = posicionX;
	posicionFinal[1] = posicionY;
	//cout << "PosicionX: " << posicionFinal[0] << " " << "PosicionY: " << posicionFinal[1] << endl;
}


