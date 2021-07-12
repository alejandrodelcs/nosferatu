#ifndef TP2_MONSTRUO_H
#define TP2_MONSTRUO_H
#include "ser.h"

class Monstruo : public Ser{
    public:
        Monstruo(int fila, int columna, std::string id, int vida, int ataque, int armadura, int energia);

        void mostrar();
};


#endif //TP2_MONSTRUO_H