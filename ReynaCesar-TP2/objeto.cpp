#include "objeto.h"

objeto::objeto() {
    fila=0;
    col=0;
}
void objeto::mostrar() {
    std::cout<<fila<<col<<std::endl;
}