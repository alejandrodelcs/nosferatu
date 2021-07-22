#include <iostream>
#include "objeto.h"
#include "mapa.h"

int main() {
    mapa nuevo;
    nuevo.crear();
    int opcion = -1;
    while(opcion!=0) {
        std::cout << "\ningrese la opcion deseada:"<< std::endl;
        std::cout << "\t   " << 1 << " - mostrar mapa" << std::endl;
        std::cout << "\t   " << 2 << " - mostrar informacion" << std::endl;
        std::cout << "\t   " << 3 << " - dar baja" << std::endl;
        std::cout << "\t   " << 4 << " - dar alta" << std::endl;
        std::cout << "\t   " << 5 << " - buscar por cuadrante" << std::endl;
        std::cout << "\t(" << 0 << ") - Salir del menú" << std::endl;
        std::cin>>opcion;
        switch (opcion) {
            case 1:
                nuevo.mostrar();
                break;
            case 2:
                nuevo.mostrar_informacion();
                break;
            case 3:
                nuevo.dar_baja();
                break;
            case 4:
                nuevo.dar_alta();
                break;
            case 5:
                nuevo.buscar();
                break;
            case 0:
                break;
        }
        std::cout<<"0 para cancelar sino ingrese otro numero"<<std::endl;
        std::cin>>opcion;
    }
    return 0;
}
