#include "estado.h"

Estado::Estado(const std::string &lineaArchivo) {
    this->lineaArchivo = lineaArchivo;
    this->nombreObjeto = lineaArchivo.substr(0, int(this->lineaArchivo.find(' ')));
    this->coordenada = lineaArchivo.substr(int(this->lineaArchivo.find(' ')) + 1);
}


std::string Estado::devolverNombre() {
    return (int(this->coordenada.find("CV")) != -1) ? "CV" : this->nombreObjeto;
}

int Estado::devolverCantidad() {
    return stoi((coordenada[0] != '(' && int(this->coordenada.find("CV")) == -1) ?
                this->coordenada.substr(0, this->coordenada.find(' ')) : "0");
}

int Estado::devolverPosx() {
    return stoi((int(this->coordenada.find("CV")) != -1
                 || int(NUMEROS.find(this->coordenada[0])) != -1)
                && (int(NUMEROS.find(this->nombreObjeto[0])) == -1)
                ? this->coordenada.substr(int(coordenada.find('(')) + 1,
                                          int(coordenada.find(',')) - int(coordenada.find('(')) - 1)
                : coordenada.substr(1, int(coordenada.find(',')) - 1));
}

int Estado::devolverPosy() {
    return stoi(coordenada.substr(int(coordenada.find(',')) + 2, int(coordenada.find(')')) - 2));
}

std::string Estado::devolverId() {
    return (int(lineaArchivo.find(')')) != -1) ? lineaArchivo.substr(lineaArchivo.find(')')+2) : "";
}

#include "estado.h"
