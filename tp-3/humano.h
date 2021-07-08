#ifndef TP2_HUMANO_H
#define TP2_HUMANO_H

#include "ser.h"

class Humano : public Ser {
public:
    Humano(int ancho, int alto);

    Humano() = default;

    std::string devolverSimbolo() override;

    int devolverCantidad() override;

    int devolverFila() override;

    int devolverColumna() override;

    void mostrar() override;
};

#endif //TP2_HUMANO_H
