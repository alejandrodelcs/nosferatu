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

    cantidadVertices = vertices ->obtenerLargo();
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
    	cout << "Iteracion numero: " << verticeIntermedio << endl;
    }
    //mostrarMatrices();
}

void Floyd::caminoMinimo(int origen, int destino) {

    if(matrizCaminos[origen][destino] == POSICION_NO_ENCONTRADA){
        cout << "No hay un camino que conecte " <<  vertices->consulta(origen + 1) << " con " << vertices->consulta(destino + 1);
    }else{
        cout << "El camino minimo que une " <<  vertices->consulta(origen + 1)->obtenerTerreno() << " con " << vertices->consulta(destino + 1)->obtenerTerreno();
        cout << " tiene un costo de: " << matrizCostos[origen][destino] << " y es el siguiente: ";
        cout << vertices->consulta(origen + 1)->obtenerTerreno();
        do{
            origen = matrizCaminos[origen][destino];
            cout << " -> " << vertices->consulta(origen + 1)->obtenerTerreno();
        }while(origen != destino);
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

Floyd::Floyd(Lista<Casillero*> *vertices) {
    this -> vertices = vertices;
    this -> matrizCaminos = nullptr;
    this -> matrizCostos = nullptr;
    this -> cantidadVertices = vertices->obtenerLargo();
}




